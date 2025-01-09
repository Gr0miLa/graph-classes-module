#include "Graph.hpp"
#include "AdjacencyMatrixGraph.hpp"
#include "AdjacencyListGraph.hpp"

// �����������: �������� ������������� ����� � ��� (���������������/�����������������)
Graph::Graph(size_t vertices, RepresentationType repType, GraphType graphType)
    : graphType(graphType) {
    bool isDirected = (graphType == GraphType::DIRECTED);
    switch (repType) {
    case RepresentationType::MATRIX:
        representation = std::make_unique<AdjacencyMatrixGraph>(vertices, isDirected);
        break;
    case RepresentationType::LIST:
        representation = std::make_unique<AdjacencyListGraph>(vertices, isDirected);
        break;
    default:
        throw std::invalid_argument("Unknown graph representation type");
    }
}

// ����������� �����������
Graph::Graph(Graph&& other) noexcept
    : representation(std::move(other.representation)),
    graphType(other.graphType) {}

// �������� �����������
Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        // ������� ����������� ������� �������� �������
        // std::unique_ptr ������������� �������������, ��� ��� ���������� ����������� ����� ������

        representation = std::move(other.representation); // ���������� ���������� ���������
        graphType = other.graphType; // �������� ��� �����
    }
    return *this;
}

// ���������� �����
void Graph::addEdge(size_t src, size_t dst) {
    representation->addEdge(src, dst);
}

// �������� �����
void Graph::removeEdge(size_t src, size_t dst) {
    representation->removeEdge(src, dst);
}

// �������� �� ������� �����
bool Graph::hasEdge(size_t src, size_t dst) const {
    return representation->hasEdge(src, dst);
}

// ���������� �������
void Graph::addVertex() {
    representation->addVertex();
}

// �������� �������
void Graph::removeVertex(size_t vertex) {
    representation->removeVertex(vertex);
}

// ����� �����
void Graph::printGraph() const {
    return representation->printGraph();
}

// ��������� ������� ������
std::vector<size_t> Graph::getAdjVertices(size_t vertex) const {
    return representation->getAdjVertices(vertex);
}

// ��������� ���������� ������
size_t Graph::getNumberOfVertices() const {
    return representation->getNumberOfVertices();
}

// ��������� ���������� ����
size_t Graph::getNumberOfEdges() const {
    return representation->getNumberOfEdges();
}
