#include "PathGraph.hpp"

// ����������� ��� �������� �����-����
PathGraph::PathGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 2) {
        throw std::invalid_argument("Path graph requires at least 2 vertices.");
    }
    // ������� ����, �������� ���������������� �������
    for (size_t i = 0; i < vertices - 1; ++i) {
        graph.addEdge(i, i + 1);
    }
}

// ��������� �������� �����
const Graph& PathGraph::getGraph() const {
    return graph;
}

// ����� ���� �� �������
void PathGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string PathGraph::getName() const {
    return "P(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
