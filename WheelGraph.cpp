#include "WheelGraph.hpp"

// ����������� ��� �������� ����� ������
WheelGraph::WheelGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 4) {
        throw std::invalid_argument("Wheel graph requires at least 4 vertices.");
    }

    size_t centerVertex = 0;  // ����������� �������
    size_t numVertices = vertices;

    // ������� ����
    for (size_t i = 1; i < numVertices - 1; ++i) {
        graph.addEdge(i, i + 1);  // ��������� ������� �����
    }
    graph.addEdge(numVertices - 1, 1);  // �������� ����

    // ��������� ���� �� ����������� ������� � ���������
    for (size_t i = 1; i < numVertices; ++i) {
        graph.addEdge(centerVertex, i);
    }
}

// ��������� �������� �����
const Graph& WheelGraph::getGraph() const {
    return graph;
}

// ����� ����� �� �������
void WheelGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string WheelGraph::getName() const {
    return "Wheel(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
