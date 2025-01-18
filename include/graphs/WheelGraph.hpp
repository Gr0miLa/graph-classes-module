#pragma once
#include "Graph.hpp"
#include <iostream>
#include <string>

// Класс для представления графа колесо
class WheelGraph {
private:
    Graph graph;

public:
    WheelGraph(size_t vertices, 
        Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
