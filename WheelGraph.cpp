#include "WheelGraph.hpp"

// Конструктор для создания графа колесо
WheelGraph::WheelGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 4) {
        throw std::invalid_argument("Wheel graph requires at least 4 vertices.");
    }

    size_t centerVertex = 0;  // Центральная вершина
    size_t numVertices = vertices;

    // Создаем цикл
    for (size_t i = 1; i < numVertices - 1; ++i) {
        graph.addEdge(i, i + 1);  // Соединяем вершины цикла
    }
    graph.addEdge(numVertices - 1, 1);  // Замкнуть цикл

    // Добавляем рёбра от центральной вершины к остальным
    for (size_t i = 1; i < numVertices; ++i) {
        graph.addEdge(centerVertex, i);
    }
}

// Получение базового графа
const Graph& WheelGraph::getGraph() const {
    return graph;
}

// Вывод графа на консоль
void WheelGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string WheelGraph::getName() const {
    return "Wheel(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
