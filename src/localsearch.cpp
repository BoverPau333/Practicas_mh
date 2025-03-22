#include <cassert>
#include <localsearch.h>
#include <iostream>
#include <unordered_set>
#include <psnimp.h>

using namespace std;



/**
 * Create random solutions until maxevals has been achieved, and returns the
 * best one.
 *
 * @param problem The problem to be optimized
 * @param maxevals Maximum number of evaluations allowed
 * @return A pair containing the best solution found and its fitness
 */
ResultMH LocalSearch::optimize(Problem *problem, int maxevals) {
  assert(maxevals > 0);
  cout << "EMpieza"; 
  ProblemSNIMP *snimp  = dynamic_cast<ProblemSNIMP*>(problem);

  tSolution best; 
  double best_fitness = -1;
  //for( int i = 0; i< n_eje; i++){}

  tSolution solution = problem->createSolution();
  best_fitness = snimp->fitness(solution);
  best = solution;

  int eval_count = 1;             // ya evaluamos la solución inicial
  int count_sin_mejora = 0;       // contador de iteraciones sin mejora
  bool parada_sin_mejora , parada_iter = false; //parada
  unordered_set<size_t> usados(solution.begin(),solution.end());
  
  cout << "llega al if"; 
  if(small){
    while(!parada_sin_mejora && !parada_iter){
      solution = best;

      int pos_sel = Random::get<int>(0, solution.size() - 1);
      
      size_t candidate;
      do {
        candidate = Random::get<size_t>(0, snimp->getNumEdges()-1);  // problem->n: total de nodos
      } while(usados.find(candidate) != usados.end());
      
      solution[pos_sel] = candidate;
      double new_fitness = problem->fitness(solution);
      eval_count++;

      if(new_fitness > best_fitness)
      {
        best = solution;
        best_fitness = new_fitness;

        usados.clear(); // Actualizamos el conjunto de usados (los nodos seleccionados en la solución actual)
        for(auto elem : solution) {
          usados.insert(elem);
        }

        parada_sin_mejora = 0;

      } else {count_sin_mejora++;}

      if(eval_count >= maxevals){ parada_iter = true; }
      if(count_sin_mejora >= 20){ parada_sin_mejora = true; }
    }
  } else {
    while(!parada_iter){
      solution = best;

      int pos_sel = Random::get<int>(0, solution.size() - 1);
      
      size_t candidate;
      do {
        candidate = Random::get<size_t>(0, snimp->getNumEdges()-1);  // problem->n: total de nodos
      } while(usados.find(candidate) != usados.end());
      
      solution[pos_sel] = candidate;
      double new_fitness = problem->fitness(solution);
      eval_count++;

      if(new_fitness > best_fitness)
      {
        best = solution;
        best_fitness = new_fitness;

        usados.clear(); // Actualizamos el conjunto de usados (los nodos seleccionados en la solución actual)
        for(auto elem : solution) {
          usados.insert(elem);
        }
      }

      if(eval_count >= maxevals)
      {
        parada_iter = true;
      }

    }
  }

  return ResultMH(best, best_fitness, maxevals);
}
