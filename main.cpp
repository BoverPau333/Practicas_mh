#include <iostream>
#include <problem.h>
#include <random.hpp>
#include <string>
#include <util.h>

// Real problem class
#include "psnimp.h"

// All all algorithms
#include "greedy.h"
#include "randomsearch.h"
#include "localsearch.h"


using namespace std;
int main(int argc, char *argv[]) {
  long int seed;
  bool Small = true;

  // Seed the random number generator
  if (argc == 1) {
    // Use a fixed seed for reproducibility
    seed = 42;
  } else {
    seed = atoi(argv[1]);
  }

  // Create the specific problem
  size_t size = 10;
  ProblemSNIMP rproblem = ProblemSNIMP("../MH/datos/ca-GrQc.txt");
  rproblem.setSize(size);

  
  // Create the algorithms
  RandomSearch ralg = RandomSearch();
  GreedySearch rgreedy = GreedySearch();
  LocalSearch localSearch = LocalSearch(!Small);
  LocalSearch localSearchSmall = LocalSearch(Small);
  
  vector<int> vector_iters = {100, 1, 1000, 1000};
  
  // Solve using evaluations
  vector<pair<string, MH *>> algoritmos = {make_pair("RandomSearch", &ralg),
                                           make_pair("Greedy", &rgreedy),
                                           make_pair("Local Search", &localSearch),
                                           make_pair("Local Search Small", &localSearchSmall)
                                           };
  Problem *problem = dynamic_cast<Problem *>(&rproblem);

  for (int i = 0; i < algoritmos.size(); i++) {
    Random::seed(seed);
    cout << algoritmos[i].first << endl;
      MH *mh = algoritmos[i].second;
      ResultMH result = mh->optimize(problem, vector_iters[i]);
      cout << "Best solution: " << result.solution << endl;
      cout << "Best fitness: " << result.fitness << endl;
      cout << "Evaluations: " << result.evaluations << endl;
    }
  

  return 0;
}
