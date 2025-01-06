//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_TOURNAMENTSELECTION_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_TOURNAMENTSELECTION_H_

#include "SelectionStrategy.h"
namespace pea_tsp::ga {

class TournamentSelection : public SelectionStrategy {
 public:
  TournamentSelection() = default;

  std::vector<Path> operator()(std::vector<Path> population) const final;

 private:
  static const Path &RandParent(const Path &a, const Path &b) ;
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_SELECTIONSTRATEGIES_TOURNAMENTSELECTION_H_
