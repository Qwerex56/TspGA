//
// Created by qwere on 05.01.2025.
//

#include <random>
#include "InsertMutation.h"

namespace pea_tsp::ga {

Path InsertMutation::operator()(const Path &path) {
  auto mutation = path.GetPath();

  auto vert_a = GetRandInt(0, (int)mutation.size());
  auto vert_b = GetRandInt(0, (int)mutation.size());

  auto temp = mutation[vert_a];

  mutation.erase(mutation.begin() + vert_a);
  mutation.insert(mutation.begin() + vert_b, temp);

  return Path{path.GetGraph(), mutation};
}

int InsertMutation::GetRandInt(int min, int max) {
  auto random_device = std::random_device{};
  auto gen = std::mt19937(random_device());
  auto r_dist = std::uniform_int_distribution<>(min, max);

  return r_dist(gen);
}
} // ga
// pea_tsp