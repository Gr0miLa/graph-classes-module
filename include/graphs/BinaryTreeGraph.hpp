#pragma once
#include "Graph.hpp"
#include <iostream>
#include <string>

// Класс для представления графа бинарного дерева
class BinaryTreeGraph {
private:
    Graph graph;
    void buildBinaryTree(size_t current, size_t maxVertices);

public:
    BinaryTreeGraph(size_t vertices, 
        Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
