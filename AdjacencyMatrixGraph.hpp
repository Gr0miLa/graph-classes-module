#pragma once

#include "IGraphRepresentation.hpp"
#include <iostream>
#include <vector>

class AdjacencyMatrixGraph : public IGraphRepresentation {
private:
    std::vector<std::vector<bool>> matrix;      // Матрица смежности
    size_t numOfVertices;                       // Количество вершин
    size_t numOfEdges;                          // Количество рёбер
    bool directed;                              // Ориентированность

public:
    AdjacencyMatrixGraph(size_t vertices = 0, bool directed = 0); // Конструктор

    void addEdge(size_t src, size_t dst) override;
    void removeEdge(size_t src, size_t dst) override;
    bool hasEdge(size_t src, size_t dst) const override;
    void addVertex() override;
    void removeVertex(size_t vertex) override;
    std::vector<size_t> getAdjVertices(size_t vertex) const override;
    size_t getNumberOfVertices() const override;
    size_t getNumberOfEdges() const override;
    void printGraph() const override;
};
