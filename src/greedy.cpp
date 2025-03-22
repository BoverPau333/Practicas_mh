#include <cassert>
#include <greedy.h>
#include <iostream>
#include <psnimp.h>


using namespace std;

template <class T> void print_vector(string name, const vector<T> &sol) {
  cout << name << ": ";

  for (auto elem : sol) {
    cout << elem << ", ";
  }
  cout << endl;
}

/**
 * Create random solutions until maxevals has been achieved, and returns the
 * best one.
 *
 * @param problem The problem to be optimized
 * @param maxevals Maximum number of evaluations allowed
 * @return A pair containing the best solution found and its fitness
 */
ResultMH GreedySearch::optimize(HeuristicProblem *problem, int maxevals) {
  ProblemSNIMP *snimp  = dynamic_cast<ProblemSNIMP*>(problem);

  assert(maxevals > 0);
  vector<tOption> values;
  tSolution sol(problem->getSolutionSize());
  vector<double>sol_h(problem->getSolutionSize());
  //print_vector("sol_initial", sol);

  int size = problem->getSolutionSize();
  int num_nod = snimp->getNumNodes();

  //Inicializo candidatos
  for (int i = 0; i < num_nod; i++) {
    values.push_back(i);
  }

  
  for (int r = 0; r <= size; r++) {  
    vector<double> heuristics = problem->heuristic(sol, values);
    
    auto posi = max_element(heuristics.begin(), heuristics.end());
    int posi_max_int = posi - heuristics.begin();
    //cout << *posi << " , " << posi_max_int << endl;

    auto pos_sol = min_element(sol_h.begin(), sol_h.end());
    int pos_sol_int = pos_sol - sol_h.begin();
    //cout << *pos_sol << " , " << pos_sol_int << endl;

    if(*posi>=*pos_sol){
      sol[pos_sol_int] = posi_max_int;
      sol_h[pos_sol_int] = *posi;
      values[posi_max_int] = values.back();
      values.pop_back();
      //print_vector("sol", sol);
    }
  }

  tFitness fitness = problem->fitness(sol);
  return ResultMH(sol, fitness, 1);
}
