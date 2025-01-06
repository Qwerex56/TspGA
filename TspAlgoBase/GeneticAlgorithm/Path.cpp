//
// Created by qwere on 05.01.2025.
//

#include "Path.h"

namespace pea_tsp::ga {
Path::Path(Graph *graph, const std::vector<int> &path) {
  graph_ = graph;
  path_ = path;
}

int Path::GetTravelWeight() const {
  auto weight = 0;

  for (auto i = 0; i < path_.size() - 1; ++i) {
    auto travel_weight = graph_->GetTravelWeight(path_[i], path_[i + 1]);

    if (travel_weight <= -1) {
      weight = -1;
      break;
    }

    weight += travel_weight;
  }

  if (weight > -1) {
    auto travel_weight = graph_->GetTravelWeight(path_.back(), path_.front());

    weight += travel_weight;
    if (travel_weight <= -1) {
      weight = -1;
    }
  }
  return weight;
}

std::vector<int> Path::GetPath() const {
  return path_;
}

bool operator==(const Path &a, const Path &b) {
  return a.GetTravelWeight() == b.GetTravelWeight();
}

bool operator<(const Path &a, const Path &b) {
  return a.GetTravelWeight() < b.GetTravelWeight();
}

Graph *Path::GetGraph() const {
  return graph_;
}

} // ga
// pea_tsp