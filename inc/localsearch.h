#pragma once
#include <mh.h>

using namespace std;

/**
 * Implementation of the Local Search metaheuristic
 * 
 * @see MH
 * @see Problem
 */
class LocalSearch : public MH {
private:
  bool small;
  int n_eje = 5;


public:
  LocalSearch(bool Small) : MH(),  small(Small) {}
  virtual ~LocalSearch() {}
  // Implement the MH interface methods
  /**
   * Create random solutions until maxevals has been achieved, and returns the
   * best one.
   *
   * @param problem The problem to be optimized
   * @param maxevals Maximum number of evaluations allowed
   * @return A pair containing the best solution found and its fitness
   */
  ResultMH optimize(Problem *problem, int maxevals) override;
};
