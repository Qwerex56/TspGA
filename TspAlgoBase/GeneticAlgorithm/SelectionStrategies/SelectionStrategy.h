//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_SELECTIONSTRATEGY_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_SELECTIONSTRATEGY_H_

#include "../../../Graph/Graph.h"
#include "../Path.h"

namespace pea_tsp::ga {

class SelectionStrategy {
 public:
  SelectionStrategy() = default;

  virtual std::vector<Path> operator ()(std::vector<Path> population) const = 0;

 protected:
  static std::vector<int> GetPopulationWeights(const std::vector<Path>& population) ;
  int GetIndividualWeight(Path individual) const;
};

} // helpers
// ga
// algo
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_SELECTIONSTRATEGY_H_
