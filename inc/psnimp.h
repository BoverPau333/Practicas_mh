#pragma once
#include <algorithm>
#include <heuristicproblem.h>
#include <set>

using namespace std;

class ProblemSNIMP : public HeuristicProblem {
  private:
    bool** adjacencyMatrix;
    size_t size;
    size_t numNodes;
    size_t numEdges;
    const int env = 10;
    const double p = 0.01;

  public:
    //Constructor
    ProblemSNIMP(const std::string& filePath = "");
    //Destructor
    ~ProblemSNIMP();
    //Cargador de archivo
    void loadFile(const std::string& filePath);

    void displayMatrix() const;

    void getSizeProblem() const;

    tFitness fitness(const tSolution &solution) override;
    
    tSolution createSolution() override;
    
    std::pair<tDomain, tDomain> getSolutionDomainRange() override {
      return std::make_pair(false, true);
    }

    vector<tHeuristic> heuristic(tSolution &sol, const vector<tOption> &options);

    int get_vecinos(int u);

    // Getters y setters
    size_t getNumNodes() const { return numNodes; }
    size_t getNumEdges() const { return numEdges; }
    void   setSize(size_t s) { size = s; }
    size_t getSolutionSize() override { return size; }
};
