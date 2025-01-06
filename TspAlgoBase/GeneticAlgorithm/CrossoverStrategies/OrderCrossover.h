//
// Created by qwere on 06.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_ORDERCROSSOVER_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_ORDERCROSSOVER_H_

#include "CrossoverStrategy.h"

namespace pea_tsp::ga {

class OrderCrossover : public CrossoverStrategy {
 public:
  OrderCrossover() = default;

  Path operator()(const Path& parent_a, const Path &parent_b) const final;
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_CROSSOVERSTRATEGIES_ORDERCROSSOVER_H_
