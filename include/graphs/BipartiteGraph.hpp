#pragma once
#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <string>

// Класс для представления двудольного графа
class BipartiteGraph {
private:
    Graph graph;
    std::vector<size_t> set1;
    std::vector<size_t> set2;

public:
    BipartiteGraph(const std::vector<size_t>& set1, const std::vector<size_t>& set2,
        Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
