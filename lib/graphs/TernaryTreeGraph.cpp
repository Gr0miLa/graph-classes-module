#include "TernaryTreeGraph.hpp"

// ����������� ��� �������� ����� 3-������
TernaryTreeGraph::TernaryTreeGraph(size_t vertices, Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices == 0) {
        throw std::invalid_argument("Ternary tree must have at least one vertex.");
    }
    buildTernaryTree(0, vertices);
}

// ��������������� ����� ��� ���������� 3-������
void TernaryTreeGraph::buildTernaryTree(size_t current, size_t maxVertices) {
    size_t firstChild = 3 * current + 1;
    size_t secondChild = 3 * current + 2;
    size_t thirdChild = 3 * current + 3;

    if (firstChild < maxVertices) {
        graph.addEdge(current, firstChild);
        buildTernaryTree(firstChild, maxVertices);
    }

    if (secondChild < maxVertices) {
        graph.addEdge(current, secondChild);
        buildTernaryTree(secondChild, maxVertices);
    }

    if (thirdChild < maxVertices) {
        graph.addEdge(current, thirdChild);
        buildTernaryTree(thirdChild, maxVertices);
    }
}

// ��������� �������� �����
const Graph& TernaryTreeGraph::getGraph() const {
    return graph;
}

// ����� ���� �� �������
void TernaryTreeGraph::printGraph() const {
    graph.printGraph();
}

// ��������� ����������� �����
std::string TernaryTreeGraph::getName() const {
    return "3-Tree(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
