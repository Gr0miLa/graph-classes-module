#pragma once
#include "Graph.hpp"
#include <iostream>
#include <string>

// Класс для представления графа 3-дерева
class TernaryTreeGraph {
private:
    Graph graph;
    void buildTernaryTree(size_t current, size_t maxVertices);

public:
    TernaryTreeGraph(size_t vertices, 
        Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
