#include <algorithm>
#include <psnimp.h>
#include <random.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

ProblemSNIMP::ProblemSNIMP(const string& filePath) : adjacencyMatrix(nullptr) {
    size = 0;
    if(filePath != ""){ loadFile(filePath); }
}

ProblemSNIMP::~ProblemSNIMP() {
    if (adjacencyMatrix) {
        for (size_t i = 0; i < size; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
    adjacencyMatrix = nullptr;
}

void ProblemSNIMP::loadFile(const string& filePath) {
    ifstream infile(filePath);
    if (!infile.is_open()) {
        cerr << "Error al abrir el archivo: " << filePath << endl;
        return;
    }

    // Liberar la matriz de adyacencia si ya existe
    if (adjacencyMatrix != nullptr && size>0) {
        for (size_t i = 0; i < size; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
        adjacencyMatrix = nullptr;
    }

    string line;
    // Leer comentarios y extraer tamaño y número de aristas
    while (getline(infile, line)) {
        if (line.empty()) continue;
        if (line[0] == '#') {
            // Buscamos la línea que contenga la información de nodos y aristas
            if (line.find("Nodes:") != string::npos && line.find("Edges:") != string::npos) {
                // Ejemplo de línea: "# Nodes: 22687 Edges: 54705"
                size_t posNodes = line.find("Nodes:");
                size_t posEdges = line.find("Edges:");
                if (posNodes != string::npos && posEdges != string::npos) {
                    // Extraer los números usando un stream sobre la subcadena
                    istringstream iss(line.substr(posNodes));
                    string dummy;
                    iss >> dummy;    // Lee "Nodes:"
                    iss >> numNodes;     // Número de nodos
                    iss >> dummy;    // Lee "Edges:"
                    iss >> numEdges; // Número de aristas
                }
            }
            continue;
        } else {
            // Si se encuentra una línea que no es comentario, reposicionamos el stream
            // Retrocedemos para procesar esta línea en el siguiente bucle
            infile.seekg(-static_cast<int>(line.size()) - 1, ios_base::cur);
            break;
        }
    }

    // Inicializar la matriz de adyacencia (tamaño: size x size)
    adjacencyMatrix = new bool*[numNodes];
    for(size_t i = 0; i < numNodes; ++i){
        adjacencyMatrix[i] = new bool[numNodes];
        fill(adjacencyMatrix[i], adjacencyMatrix[i] + numNodes, false);
    }

    // Leer las conexiones (cada línea contiene: FromNodeId  ToNodeId)
    size_t count;
    size_t from, to;
    while(infile >> from >> to){
        adjacencyMatrix[from][to] = true;
    }
    infile.close();
}


void ProblemSNIMP::displayMatrix() const {
    for (size_t i = 0; i < numNodes; ++i) {
        for (size_t j = 0; j < numNodes; ++j) {
            cout << (adjacencyMatrix[i][j] ? "1 " : "");
        }
        cout << endl;
    }
}

void ProblemSNIMP::getSizeProblem() const{
    cout << getNumEdges() << " , " << getNumNodes() << endl; 
}

/*
tFitness ProblemSNIMP::fitness(const tSolution &solution) {
    double count = 0;
    set<size_t> B;
    set<size_t> A;
    set<size_t> A_star;

    for(int i=0 ; i<env; i++){   
        A_star.clear();
        A.clear();

        A.insert(solution.begin(),solution.end());
        A_star.insert(solution.begin(),solution.end());

        while(!A.empty()){
            B.clear();
            for (const auto& v : A) {
                for(int j=0 ; j < numNodes ; j++){
                    if(adjacencyMatrix[v][j]){
                        if(Random::get<double>(0.0, 1.0) <= p){
                            B.insert(j);
                        }
                    }
                }
            }
            A_star.insert(B.begin(), B.end());
            A = B;
        }
        count += A_star.size();
    }
    return count/env;
}
*/


tFitness ProblemSNIMP::fitness(const tSolution &solution) {
    tFitness count = 0;
    //contar cuantos ha contagiado
    //para ello realizo el contagio
    for(int k = 0; k < env; k++){
          //nodos contagiados totales
        vector<int> contagiadosIni = solution;
        vector<int> contagiadosTotal = solution;

        while(!contagiadosIni.empty()){
            vector<int> newContagios;
            for(int i = 0; i < contagiadosIni.size(); i++){
                for(int j = 0; j < numNodes ; j++){
                    if(adjacencyMatrix[contagiadosIni[i]][j] && find(newContagios.begin(), newContagios.end(), j) == newContagios.end()){ //si estan conectados y no esta ya metido j en contagiados
                        if(Random::get<float>(0, 1) <= p){
                            newContagios.push_back(j);
                        }
                    }
                }
            }
            contagiadosTotal.insert(contagiadosTotal.end(), newContagios.begin(), newContagios.end());
            contagiadosIni = newContagios;
        }
        count += contagiadosTotal.size();
    }
 
    return count / env;

}


tSolution ProblemSNIMP::createSolution(){
  tSolution solution(size);
  set<int> used_sol;
  int candidate_sol;
  for (int i = 0; i < solution.size(); i++) {

    do{
        candidate_sol = Random::get<int>(0,numNodes-1);
    }while(used_sol.count(candidate_sol) != 0);

    solution[i] = candidate_sol;
    used_sol.emplace(candidate_sol);
  }

  return solution;
}

vector<tHeuristic> ProblemSNIMP::heuristic(tSolution &sol,
                                            const vector<tOption> &options) {
    vector<tHeuristic> values(options.size(), 0);
    
   for (size_t i = 0; i < options.size(); ++i) {
        auto option = options[i];
        tHeuristic gne = get_vecinos(option);
        // Añadir la suma de outDegrees de los vecinos de u
        for (size_t v = 0; v < numNodes; ++v) {
            if (adjacencyMatrix[option][v]) {
                gne += get_vecinos(v);
            }
        }

        values[i] = gne;
    }

    return values;
}

int ProblemSNIMP::get_vecinos(int u) {
    // Verifica que u esté en el rango correcto
    if(u < 0 || u >= numNodes) {
        throw std::out_of_range("Índice de nodo fuera de rango");
    }
    
    int count = 0;
    // Recorre la fila u de la matriz
    for (int j = 0; j < numNodes; j++) {
        if (adjacencyMatrix[u][j] == true) {
            count++;
        }
    }
    return count;
}

