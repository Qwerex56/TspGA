//
// Created by qwere on 05.01.2025.
//

#ifndef TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_INSERTMUTATION_H_
#define TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_INSERTMUTATION_H_

#include "MutationStrategy.h"
namespace pea_tsp::ga {

class InsertMutation : public MutationStrategy {
 public:
  InsertMutation() = default;

  Path operator()(const Path &path) final;

 private:
  static int GetRandInt(int min, int max) ;
};

} // ga
// pea_tsp

#endif //TSPGA_TSPALGOBASE_GENETICALGORITHM_MUTATIONSSTRATEGIES_INSERTMUTATION_H_
