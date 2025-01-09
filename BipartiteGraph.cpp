#include "BipartiteGraph.hpp"

// Конструктор для создания двудольного графа
BipartiteGraph::BipartiteGraph(const std::vector<size_t>& set1, const std::vector<size_t>& set2,
    Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(set1.size() + set2.size(), repType, graphType), set1(set1), set2(set2) {
    // Проверяем, что множества непересекающиеся
    for (size_t vertex1 : set1) {
        for (size_t vertex2 : set2) {
            if (vertex1 == vertex2) {
                throw std::invalid_argument("Sets in bipartite graph must be disjoint.");
            }
        }
    }

    // Добавляем рёбра между каждой вершиной из set1 и каждой вершиной из set2
    for (size_t vertex1 : set1) {
        for (size_t vertex2 : set2) {
            graph.addEdge(vertex1, vertex2);
        }
    }
}

// Получение базового графа
const Graph& BipartiteGraph::getGraph() const {
    return graph;
}

// Печать двудольного разбиения
void BipartiteGraph::printGraph() const {
    std::cout << "Set 1: ";
    for (size_t vertex : set1) {
        std::cout << vertex << " ";
    }
    std::cout << "\nSet 2: ";
    for (size_t vertex : set2) {
        std::cout << vertex << " ";
    }
    std::cout << "\n";

    
    graph.printGraph();
}

// Получение обозначения графа
std::string BipartiteGraph::getName() const {
    return "K(" + std::to_string(set1.size()) + ", " + std::to_string(set2.size()) + ")";
}
