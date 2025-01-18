#include "CompleteGraph.hpp"

// ����������� ��� �������� ������� �����
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

// ��������� �������� �����
const Graph& CompleteGraph::getGraph() const {
    return graph;
}

// ����� ����� �� �������
void CompleteGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string CompleteGraph::getName() const {
    return "K(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
