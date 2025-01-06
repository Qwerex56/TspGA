//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_PROPORTIONALSELECTION_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_PROPORTIONALSELECTION_H_

#include "./SelectionStrategy.h"

namespace pea_tsp::ga {

class ProportionalSelection : public SelectionStrategy {
 public:
  ProportionalSelection() = default;

  std::vector<Path> operator()(std::vector<Path> population) const final;
};

} // helpers
// ga
// algo
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_PROPORTIONALSELECTION_H_
