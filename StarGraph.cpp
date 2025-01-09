#include "StarGraph.hpp"

// Конструктор для создания графа звезда
StarGraph::StarGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 2) {
        throw std::invalid_argument("Star graph requires at least 2 vertices.");
    }

    size_t centerVertex = 0;  // Центральная вершина
    for (size_t i = 1; i < vertices; ++i) {
        graph.addEdge(centerVertex, i);  // Добавляем рёбра от центра к остальным вершинам
    }
}

// Получение базового графа
const Graph& StarGraph::getGraph() const {
    return graph;
}

// Вывод графа на консоль
void StarGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string StarGraph::getName() const {
    return "Star(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
