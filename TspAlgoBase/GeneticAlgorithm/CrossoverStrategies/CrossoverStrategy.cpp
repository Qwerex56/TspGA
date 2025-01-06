//
// Created by qwere on 06.01.2025.
//

#include <random>
#include "CrossoverStrategy.h"

namespace pea_tsp::ga {

int CrossoverStrategy::GetRandInt(int min, int max) {
  auto random_device = std::random_device{};
  auto gen = std::mt19937(random_device());
  auto r_dist = std::uniform_int_distribution<>(min, max);

  return r_dist(gen);
}

} // ga
// pea_tsp