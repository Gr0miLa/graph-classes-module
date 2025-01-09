#pragma once

#include <memory>
#include <vector>
#include "IGraphRepresentation.hpp"
#include <iostream>

class Graph {
public:
    enum class RepresentationType { MATRIX, LIST };         // Способ представлния графа
    enum class GraphType { DIRECTED, UNDIRECTED };          // Тип графа

    Graph(size_t vertices, RepresentationType repType, 
        GraphType graphType);                               // Конструктор
    Graph(Graph&& other) noexcept;                          // Конструктор перемещения
    Graph& operator=(Graph&& other) noexcept;               // Оператор перемещения
    ~Graph() = default;                                     // Деструктор по умолчанию

    void addEdge(size_t src, size_t dst);                   // Добавление ребра в граф
    void removeEdge(size_t src, size_t dst);                // Удаление ребра из графа
    bool hasEdge(size_t src, size_t dst) const;             // Проверка на наличие ребра в графе
    void addVertex();                                       // Добавление вершины в граф
    void removeVertex(size_t vertex);                       // Удаление вершины из графа
    std::vector<size_t> getAdjVertices(size_t vertex) const;// Получение вектора смежных вершин
    size_t getNumberOfVertices() const;                     // Получение количества вершин в графе
    size_t getNumberOfEdges() const;                        // Получение количества рёбер в графе
    void printGraph() const;                                // Вывод графа в консоль

private:
    std::unique_ptr<IGraphRepresentation> representation;   // Представление графа
    GraphType graphType;                                    // Тип графа
};
