//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_RANKINGSELECTION_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_RANKINGSELECTION_H_

#include "SelectionStrategy.h"

namespace pea_tsp::ga {

class RankingSelection : public SelectionStrategy {
 public:
  RankingSelection() = default;

  std::vector<Path> operator()(std::vector<Path> population) const final;
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_RANKINGSELECTION_H_
