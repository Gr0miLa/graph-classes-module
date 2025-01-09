#include "StarGraph.hpp"

// ����������� ��� �������� ����� ������
StarGraph::StarGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 2) {
        throw std::invalid_argument("Star graph requires at least 2 vertices.");
    }

    size_t centerVertex = 0;  // ����������� �������
    for (size_t i = 1; i < vertices; ++i) {
        graph.addEdge(centerVertex, i);  // ��������� ���� �� ������ � ��������� ��������
    }
}

// ��������� �������� �����
const Graph& StarGraph::getGraph() const {
    return graph;
}

// ����� ����� �� �������
void StarGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string StarGraph::getName() const {
    return "Star(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
