#include "CompleteGraph.hpp"

// Конструктор для создания полного графа
CompleteGraph::CompleteGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    for (size_t i = 0; i < vertices; ++i) {
        for (size_t j = 0; j < vertices; ++j) {
            if (i != j) {
                graph.addEdge(i, j);
            }
        }
    }
}

// Получение базового графа
const Graph& CompleteGraph::getGraph() const {
    return graph;
}

// Вывод цикла на консоль
void CompleteGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string CompleteGraph::getName() const {
    return "K(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
