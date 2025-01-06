//
// Created by qwere on 05.01.2025.
//

#include "SelectionStrategy.h"

namespace pea_tsp::ga {

std::vector<int> SelectionStrategy::GetPopulationWeights(const std::vector<Path>& population) {
  auto weights = std::vector<int>(population.size());

  for (const auto &path : population) {
    weights.emplace_back(path.GetTravelWeight());
  }

  return weights;
}

} // ga
// pea_tsp
