#pragma once

#include <vector>
#include <cstddef>

class IGraphRepresentation {
public:
    virtual ~IGraphRepresentation() = default;                              // Виртуальный деструктор

    virtual void addEdge(size_t src, size_t dst) = 0;                       // Добавление ребра в граф
    virtual void removeEdge(size_t src, size_t dst) = 0;                    // Удаление ребра из графа
    virtual bool hasEdge(size_t src, size_t dst) const = 0;                 // Проверка на наличие ребра в графе
    virtual void addVertex() = 0;                                           // Добавление вершины в граф
    virtual void removeVertex(size_t vertex) = 0;                           // Удаление вершины из графа
    virtual std::vector<size_t> getAdjVertices(size_t vertex) const = 0;    // Получение вектора смежных вершин
    virtual size_t getNumberOfVertices() const = 0;                         // Получение количества вершин в графе
    virtual size_t getNumberOfEdges() const = 0;                            // Получение количества рёбер в графе
    virtual void printGraph() const = 0;                                    // Вывод графа в консоль
};
