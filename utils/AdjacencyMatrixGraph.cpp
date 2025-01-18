#include "AdjacencyMatrixGraph.hpp"

// �����������
AdjacencyMatrixGraph::AdjacencyMatrixGraph(size_t vertices, bool directed)
    : matrix(vertices, std::vector<bool>(vertices, false)), numOfVertices(vertices), 
    numOfEdges(0), directed(directed) {}

void AdjacencyMatrixGraph::addEdge(size_t src, size_t dst) {
    if (src >= numOfVertices || dst >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (!matrix[src][dst]) {
        matrix[src][dst] = true;
        ++numOfEdges;
        if (!directed) {
            matrix[dst][src] = true; // ��������� �������� �����
        }
    }
}

void AdjacencyMatrixGraph::removeEdge(size_t src, size_t dst) {
    if (src >= numOfVertices || dst >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (matrix[src][dst]) {
        matrix[src][dst] = false;
        --numOfEdges;
        if (!directed) {
            matrix[dst][src] = false; // ������� �������� �����
        }
    }
}

// ��������, ���������� �� ����� ����� ����� ��������� � ������� ���������
bool AdjacencyMatrixGraph::hasEdge(size_t src, size_t dst) const {
    if (src >= matrix.size() || dst >= matrix.size()) {
        return false;
    }
    return matrix[src][dst];
}

// ���������� �������
void AdjacencyMatrixGraph::addVertex() {
    // ��������� ����� ������� ��� ������ ������
    for (auto& row : matrix) {
        row.push_back(false);
    }
    // ��������� ����� ������
    matrix.emplace_back(numOfVertices + 1, false);
    ++numOfVertices;
}

// �������� �������
void AdjacencyMatrixGraph::removeVertex(size_t vertex) {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    // ��������� ���������� ����, ������ ��������� � ���� �������� ����
    for (size_t i = 0; i < numOfVertices; ++i) {
        if (matrix[vertex][i]) --numOfEdges;
        if (matrix[i][vertex]) --numOfEdges;
    }

    // ������� ������
    matrix.erase(matrix.begin() + vertex);

    // ������� �������
    for (auto& row : matrix) {
        row.erase(row.begin() + vertex);
    }

    --numOfVertices;
}

// ��������� ������ ������� ������
std::vector<size_t> AdjacencyMatrixGraph::getAdjVertices(size_t vertex) const {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return {};
    }

    std::vector<size_t> neighbors;
    for (size_t i = 0; i < numOfVertices; ++i) {
        if (matrix[vertex][i]) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// ��������� ���������� ������
size_t AdjacencyMatrixGraph::getNumberOfVertices() const {
    return numOfVertices;
}

// ��������� ���������� ����
size_t AdjacencyMatrixGraph::getNumberOfEdges() const {
    return numOfEdges;
}

// ����� �����
void AdjacencyMatrixGraph::printGraph() const {
    for (int j = 0; j < getNumberOfVertices() + 1; ++j) {
        if (j == 0) {
            std::cout << "   ";
        }
        else {
            std::cout << j - 1 << " ";
        }
    }
    std::cout << "\n";
    for (size_t i = 0; i < getNumberOfVertices(); ++i) {
        std::cout << i << ": ";
        for (size_t elem : matrix[i]) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
}
