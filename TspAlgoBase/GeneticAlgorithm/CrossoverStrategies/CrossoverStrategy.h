//
// Created by qwere on 06.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_CROSSOVERSTRATEGY_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_CROSSOVERSTRATEGY_H_

#include "../Path.h"
namespace pea_tsp::ga {

class CrossoverStrategy {
 public:
  CrossoverStrategy() = default;

  virtual Path operator()(const Path& parent_a, const Path &parent_b) const = 0;

 protected:
  static int GetRandInt(int min, int max);
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_CROSSOVERSTRATEGY_H_
