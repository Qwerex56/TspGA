//
// Created by qwere on 06.01.2025.
//

#include <algorithm>
#include <numeric>
#include "OrderCrossover.h"

namespace pea_tsp::ga {

Path OrderCrossover::operator()(const Path &parent_a, const Path &parent_b) const {
  auto section_start = GetRandInt(0, (int)parent_a.GetPath().size() - 2);
  auto section_end = GetRandInt(section_start + 1, (int)parent_a.GetPath().size() - 1);

  auto child = std::vector<int>(parent_a.GetPath().size(), -1);

  for (auto i = section_start; i <= section_end; ++i) {
    child[i] = parent_a.GetPath()[i];
  }

  auto emplace_position = 0;

  for (int i : child) {
    if (i == -1) {
      break;
    }

    emplace_position++;
  }

  for (auto i = 0; i < parent_b.GetPath().size(); ++i) {
    auto has_vert = std::any_of(child.begin(), child.end(), [&parent_b, &i](int e) {
      return e == parent_b.GetPath()[i];
    });

    if (has_vert) {
      continue;
    }

    child[emplace_position] = parent_b.GetPath()[i];
    emplace_position += 1;
  }


  return Path{parent_a.GetGraph(), child};
}

} // ga
// pea_tsp