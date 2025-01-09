#pragma once
#include "Graph.hpp"
#include <random>
#include <iostream>
#include <string>

class RandomGraph {
private:
    Graph graph;
    size_t edgeCount;         // ����� ����
    double edgeProbability;   // ����������� ����������� ���������� ����

public:
    // �����������, ��� �������� ���������� ������ � ����
    RandomGraph(size_t vertices,
        size_t edgeCount,
        Graph::RepresentationType repType = Graph::RepresentationType::LIST,
        Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

    const Graph& getGraph() const;
    void printGraph() const;
    std::string getName() const;
};
