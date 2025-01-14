//
// Created by qwere on 13.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_GENETICALGORITHM_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_GENETICALGORITHM_H_

#include "../TspAlgoBase.h"
#include "CrossoverStrategies/CrossoverStrategy.h"
#include "MutationsStrategies/MutationStrategy.h"
#include "SelectionStrategies/SelectionStrategy.h"

namespace pea_tsp::ga {

class GeneticAlgorithm : public TspAlgoBase {
 public:
  GeneticAlgorithm() = default;
  explicit GeneticAlgorithm(const std::string &conf_path, const std::string &graph_conf_path = "");

  [[nodiscard]] std::vector<int> FindSolution() const final;

 protected:
  CrossoverStrategy *crossover_strategy_ = nullptr;
  MutationStrategy *mutation_strategy_ = nullptr;
  SelectionStrategy *selection_strategy_ = nullptr;

  [[nodiscard]] std::vector<Path> CreateInstance() const;
  [[nodiscard]] std::vector<Path> ApplySelection(std::vector<Path> &population) const;
  [[nodiscard]] std::vector<Path> ApplyCrossover(std::vector<Path> &population) const;
  [[nodiscard]] std::vector<Path> ApplyMutations(std::vector<Path> &offspring) const;

  [[nodiscard]] bool ShouldContinueAlgorithm(int current_gen) const;

  int population_count_ = 1000;
  float mutation_chance = 0.5;
  int max_generations = 1000;
  int initial_lifetime = 5;

  static Path GetBestInPopulation(std::vector<Path> &population);
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_GENETICALGORITHM_H_
