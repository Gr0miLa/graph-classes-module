#include "CycleGraph.hpp"

// ����������� ��� �������� ������������ �����
CycleGraph::CycleGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices < 3) {
        throw std::invalid_argument("Cycle graph requires at least 3 vertices.");
    }
    // ������� ����, �������� ������� �� �����
    for (size_t i = 0; i < vertices; ++i) {
        graph.addEdge(i, (i + 1) % vertices);
    }
}

// ��������� �������� �����
const Graph& CycleGraph::getGraph() const {
    return graph;
}

// ����� ����� �� �������
void CycleGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string CycleGraph::getName() const {
    return "C(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
