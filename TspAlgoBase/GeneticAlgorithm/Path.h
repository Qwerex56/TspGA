//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_PATH_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_PATH_H_

#include <vector>
#include "../../Graph/Graph.h"
namespace pea_tsp::ga {

class Path {
 public:
  Path(Graph *graph, const std::vector<int>& path);

  [[nodiscard]] int GetTravelWeight() const;
  [[nodiscard]] std::vector<int> GetPath() const;
  [[nodiscard]] Graph* GetGraph() const;

  friend bool operator ==(const Path &a, const Path &b);
  friend bool operator <(const Path &a, const Path &b);

 private:
  std::vector<int> path_;
  Graph* graph_ = nullptr;
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_PATH_H_
