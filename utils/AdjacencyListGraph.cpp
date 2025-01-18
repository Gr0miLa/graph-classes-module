#include "AdjacencyListGraph.hpp"
#include <iostream>

// Конструктор
AdjacencyListGraph::AdjacencyListGraph(size_t vertices, bool directed)
    : adjacencyList(vertices), numOfVertices(vertices), numOfEdges(0), directed(directed) {}

// Добавление ребра
void AdjacencyListGraph::addEdge(size_t src, size_t dst) {
    if (src >= adjacencyList.size() || dst >= adjacencyList.size()) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (adjacencyList[src].insert(dst).second) {
        ++numOfEdges;
        if (!directed) {
            adjacencyList[dst].insert(src);
        }
    }
}

// Удаление ребра
void AdjacencyListGraph::removeEdge(size_t src, size_t dst) {
    if (src >= numOfVertices || dst >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (adjacencyList[src].erase(dst)) {
        --numOfEdges;
        if (!directed) {
            adjacencyList[dst].erase(src);
        }
    }
}

// Проверка, существует ли ребро между двумя вершинами в списке смежности
bool AdjacencyListGraph::hasEdge(size_t src, size_t dst) const {
    if (src >= adjacencyList.size() || dst >= adjacencyList.size()) {
        return false;
    }
    return adjacencyList[src].find(dst) != adjacencyList[src].end();
}

// Добавление вершины
void AdjacencyListGraph::addVertex() {
    adjacencyList.emplace_back();
    ++numOfVertices;
}

// Удаление вершины
void AdjacencyListGraph::removeVertex(size_t vertex) {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    numOfEdges -= adjacencyList[vertex].size();

    // Удаляем все рёбра, связанные с вершиной
    for (size_t neighbor : adjacencyList[vertex]) {
        adjacencyList[neighbor].erase(vertex);
        if (directed) {
            --numOfEdges; // Учитываем только одно направление
        }
    }

    adjacencyList.erase(adjacencyList.begin() + vertex);
    --numOfVertices;

    // Корректируем индексы оставшихся вершин
    for (auto& neighbors : adjacencyList) {
        std::set<size_t> updatedNeighbors;
        for (auto neighbor : neighbors) {
            if (neighbor == vertex) {
                continue;
            }
            if (neighbor > vertex) {
                --neighbor;
            }
            updatedNeighbors.insert(neighbor);
        }
        neighbors = std::move(updatedNeighbors);
    }
}


// Получение списка смежных вершин
std::vector<size_t> AdjacencyListGraph::getAdjVertices(size_t vertex) const {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return {};
    }
    return std::vector<size_t>(adjacencyList[vertex].begin(), adjacencyList[vertex].end());
}

// Получение количества вершин
size_t AdjacencyListGraph::getNumberOfVertices() const {
    return numOfVertices;
}

// Получение количества рёбер
size_t AdjacencyListGraph::getNumberOfEdges() const {
    return numOfEdges;
}

// Вывод графа
void AdjacencyListGraph::printGraph() const {
    for (size_t i = 0; i < getNumberOfVertices(); ++i) {
        std::cout << i << ": ";
        for (size_t neighbor : getAdjVertices(i)) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}
