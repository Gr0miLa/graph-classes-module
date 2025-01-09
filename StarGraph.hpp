#pragma once
#include "Graph.hpp"
#include <iostream>
#include <string>

// Класс для представления графа звезда
class StarGraph {
private:
    Graph graph;

public:
    StarGraph(size_t vertices, 
        Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
