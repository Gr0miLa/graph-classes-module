#include "RandomGraph.hpp"

// Конструктор для создания случайного графа
RandomGraph::RandomGraph(size_t vertices, size_t edgeCount,
    Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType), edgeCount(edgeCount) {
    if (vertices < 2) {
        throw std::invalid_argument("Random graph requires at least 2 vertices.");
    }

    size_t maxPossibleEdges = vertices * (vertices - 1) / 2;
    if (edgeCount > maxPossibleEdges) {
        edgeCount = maxPossibleEdges;
        throw std::invalid_argument("The number of edges exceeds the maximum possible for the graph.");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, vertices - 1);

    size_t addedEdges = 0;

    while (addedEdges < edgeCount) {
        size_t src = dis(gen);
        size_t dst = dis(gen);

        if (src != dst && !graph.hasEdge(src, dst)) {
            graph.addEdge(src, dst);
            ++addedEdges;
        }
    }
}

// Получение базового графа
const Graph& RandomGraph::getGraph() const {
    return graph;
}

// Вывод графа на консоль
void RandomGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string RandomGraph::getName() const {
    return "RandomGraph(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
