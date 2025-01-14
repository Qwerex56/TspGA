//
// Created by qwere on 13.01.2025.
//

#include <numeric>
#include <random>
#include <iostream>
#include <fstream>
#include "GeneticAlgorithm.h"
#include "SelectionStrategies/TournamentSelection.h"
#include "CrossoverStrategies/OrderCrossover.h"
#include "MutationsStrategies/InsertMutation.h"

namespace pea_tsp::ga {

GeneticAlgorithm::GeneticAlgorithm(const std::string &conf_path, const std::string &graph_conf_path) : TspAlgoBase(
    conf_path,
    graph_conf_path) {
  selection_strategy_ = new TournamentSelection();
  crossover_strategy_ = new OrderCrossover();
  mutation_strategy_ = new InsertMutation();

  auto file = std::fstream{conf_path};

  if (!file.is_open()) {
    std::cout << "Could not open config file\n";
  } else {
    std::string line;
    std::string graph_config;

    while (!file.eof()) {
      std::getline(file, line);

      std::stringstream str_stream{line};
      std::string token;
      std::vector<std::string> tokens;

      while (std::getline(str_stream, token, '=')) {
        tokens.emplace_back(token);
      }
    }
  }
}

std::vector<int> GeneticAlgorithm::FindSolution() const {
  std::vector<Path> population = CreateInstance();

  std::pair<int, Path> yet_best_found;
  Path current_best;

  int generation = 0;

  while (ShouldContinueAlgorithm(generation)) {
    auto parents = ApplySelection(population);
    auto offspring = ApplyCrossover(parents);
    offspring = ApplyMutations(offspring);

    auto next_generation = std::vector<Path>();
    next_generation.insert(next_generation.begin(), offspring.begin(), offspring.end());
    next_generation.insert(next_generation.begin(), parents.begin(), parents.end());

    std::shuffle(next_generation.begin(), next_generation.end(), std::mt19937{std::random_device{}()});

    population = next_generation;
    ++generation;

    current_best = GetBestInPopulation(population);

    if (yet_best_found.second.GetGraph() == nullptr) {
      yet_best_found.second = current_best;
      yet_best_found.first = generation;
    } else if (current_best < yet_best_found.second) {
      yet_best_found.second = current_best;
      yet_best_found.first = generation;
    }

    if (do_show_progress_) {
      std::cout << "Best found in current gen: " << generation << "\n\tWeight: " << current_best.GetTravelWeight()
                << "\n\tPath: ";
      for (const auto &vert : current_best.GetPath()) {
        std::cout << vert << " -> ";
      }

      std::cout << std::endl;
      std::cout << std::endl;

      std::cout << "Best found yet: " << generation << "\n\tWeight: " << yet_best_found.second.GetTravelWeight()
                << "\n\tPath: ";
      for (const auto &vert : yet_best_found.second.GetPath()) {
        std::cout << vert << " -> ";
      }

      std::cout << std::endl;
      std::cout << std::endl;
      std::cout << std::endl;
    }
  }

  return current_best.GetPath();
}

Path GeneticAlgorithm::GetBestInPopulation(std::vector<Path> &population) {
  Path current_best = population.front();

  for (const auto &path : population) {
    if (path < current_best) continue;

    current_best = path;
  }

  return current_best;
}

std::vector<Path> GeneticAlgorithm::CreateInstance() const {
  auto random_pop = std::vector<Path>(population_count_);
  random_pop.resize(population_count_);

  for (auto &path : random_pop) {
    auto vertices = std::vector<int>(graph_->GetDimension());
    std::iota(vertices.begin(), vertices.end(), 1);

    std::shuffle(vertices.begin(), vertices.end(), std::mt19937{std::random_device{}()});

    path = Path{graph_, vertices};
  }

  return random_pop;
}

std::vector<Path> GeneticAlgorithm::ApplySelection(std::vector<Path> &population) const {
  return (*selection_strategy_)(population);
}

std::vector<Path> GeneticAlgorithm::ApplyCrossover(std::vector<Path> &population) const {
  // imitate random parent selection
  std::shuffle(population.begin(), population.end(), std::mt19937{std::random_device{}()});

  std::vector<Path> offspring;
  int midpoint = population.size() / 2;

  for (auto i = 0; i < midpoint; ++i) {
    auto child_a = (*crossover_strategy_)(population[i], population[i + midpoint]);
    auto child_b = (*crossover_strategy_)(population[i + midpoint], population[i]);

    offspring.emplace_back(child_a);
    offspring.emplace_back(child_b);
  }

  return offspring;
}

std::vector<Path> GeneticAlgorithm::ApplyMutations(std::vector<Path> &offspring) const {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(0.0, 1.0);

  for (auto &child : offspring) {
    auto random_chance = dis(gen);

    if (random_chance > mutation_chance) {
      continue;
    }

    child = (*mutation_strategy_)(child);
  }

  return offspring;
}

bool GeneticAlgorithm::ShouldContinueAlgorithm(int current_gen) const {
  if (current_gen >= max_generations) {
    return false;
  }

  return true;
}

} // ga
// pea_tsp