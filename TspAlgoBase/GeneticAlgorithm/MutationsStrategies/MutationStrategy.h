//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_MUTATIONSTRATEGY_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_MUTATIONSTRATEGY_H_

#include "../Path.h"
namespace pea_tsp::ga {

class MutationStrategy {
 public:
  MutationStrategy() = default;

  virtual Path operator()(const Path &path) = 0;

 protected:
  static int GetRandInt(int min, int max);
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_MUTATIONSTRATEGY_H_
