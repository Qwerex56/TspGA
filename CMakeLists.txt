cmake_minimum_required(VERSION 3.29)
project(TspGA)

set(CMAKE_CXX_STANDARD 20)

add_executable(TspGA main.cpp
        Graph/Graph.h
        Graph/AsymmetricalGraph.h
        Graph/Graph.cpp
        Graph/SymmetricalGraph.cpp
        Graph/SymmetricalGraph.h
        Graph/AsymmetricalGraph.cpp
        TspAlgoBase/TspAlgoBase.cpp
        TspAlgoBase/TspAlgoBase.h
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/SelectionStrategy.cpp
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/SelectionStrategy.h
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/ProportionalSelection.cpp
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/ProportionalSelection.h
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/TournamentSelection.cpp
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/TournamentSelection.h
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/RankingSelection.cpp
        TspAlgoBase/GeneticAlgorithm/SelectionStrategies/RankingSelection.h
        TspAlgoBase/GeneticAlgorithm/Path.cpp
        TspAlgoBase/GeneticAlgorithm/Path.h
        TspAlgoBase/GeneticAlgorithm/MutationsStrategies/MutationStrategy.cpp
        TspAlgoBase/GeneticAlgorithm/MutationsStrategies/MutationStrategy.h
        TspAlgoBase/GeneticAlgorithm/MutationsStrategies/InsertMutation.cpp
        TspAlgoBase/GeneticAlgorithm/MutationsStrategies/InsertMutation.h
        TspAlgoBase/GeneticAlgorithm/CrossoverStrategies/CrossoverStrategy.cpp
        TspAlgoBase/GeneticAlgorithm/CrossoverStrategies/CrossoverStrategy.h
        TspAlgoBase/GeneticAlgorithm/CrossoverStrategies/OrderCrossover.cpp
        TspAlgoBase/GeneticAlgorithm/CrossoverStrategies/OrderCrossover.h)
