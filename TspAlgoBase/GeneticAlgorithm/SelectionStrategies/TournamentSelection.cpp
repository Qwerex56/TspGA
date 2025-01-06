//
// Created by qwere on 05.01.2025.
//

#include <random>
#include "TournamentSelection.h"

namespace pea_tsp::ga {

std::vector<Path> TournamentSelection::operator()(std::vector<Path> population) const {
  auto mid = population.size() / 2;

  auto parents = std::vector<Path>();

  for (int i = 0; i < population.size() / 2; ++i) {
    const auto &individual_a = population[i];
    const auto &individual_b = population[i + mid];

    if (individual_a < individual_b) {
      parents.emplace_back(individual_a);
    } else if (individual_b < individual_a) {
      parents.emplace_back(individual_b);
    } else {
      parents.emplace_back(RandParent(individual_a, individual_b));
    }
  }

  return parents;
}

const Path &TournamentSelection::RandParent(const Path &a, const Path &b) {
  auto random_device = std::random_device{};
  auto gen = std::mt19937(random_device());
  auto r_dist = std::uniform_int_distribution<>(0, 1);

  return r_dist(gen) == 0? a : b;
}

} // ga
// pea_tsp