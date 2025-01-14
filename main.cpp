#include <iostream>
#include "TspAlgoBase/GeneticAlgorithm/GeneticAlgorithm.h"

int main() {
  auto solution = pea_tsp::ga::GeneticAlgorithm("./conf.txt", "./fm11_0.atsp")
      .FindSolution();

  return 0;
}
