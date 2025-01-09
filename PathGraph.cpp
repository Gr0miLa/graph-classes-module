#include "PathGraph.hpp"

// Конструктор для создания графа-пути
PathGraph::PathGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 2) {
        throw std::invalid_argument("Path graph requires at least 2 vertices.");
    }
    // Создаем путь, соединяя последовательные вершины
    for (size_t i = 0; i < vertices - 1; ++i) {
        graph.addEdge(i, i + 1);
    }
}

// Получение базового графа
const Graph& PathGraph::getGraph() const {
    return graph;
}

// Вывод пути на консоль
void PathGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string PathGraph::getName() const {
    return "P(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
