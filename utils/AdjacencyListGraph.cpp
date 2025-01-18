#include "AdjacencyListGraph.hpp"
#include <iostream>

// �����������
AdjacencyListGraph::AdjacencyListGraph(size_t vertices, bool directed)
    : adjacencyList(vertices), numOfVertices(vertices), numOfEdges(0), directed(directed) {}

// ���������� �����
void AdjacencyListGraph::addEdge(size_t src, size_t dst) {
    if (src >= adjacencyList.size() || dst >= adjacencyList.size()) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (adjacencyList[src].insert(dst).second) {
        ++numOfEdges;
        if (!directed) {
            adjacencyList[dst].insert(src);
        }
    }
}

// �������� �����
void AdjacencyListGraph::removeEdge(size_t src, size_t dst) {
    if (src >= numOfVertices || dst >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    if (adjacencyList[src].erase(dst)) {
        --numOfEdges;
        if (!directed) {
            adjacencyList[dst].erase(src);
        }
    }
}

// ��������, ���������� �� ����� ����� ����� ��������� � ������ ���������
bool AdjacencyListGraph::hasEdge(size_t src, size_t dst) const {
    if (src >= adjacencyList.size() || dst >= adjacencyList.size()) {
        return false;
    }
    return adjacencyList[src].find(dst) != adjacencyList[src].end();
}

// ���������� �������
void AdjacencyListGraph::addVertex() {
    adjacencyList.emplace_back();
    ++numOfVertices;
}

// �������� �������
void AdjacencyListGraph::removeVertex(size_t vertex) {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return;
    }

    numOfEdges -= adjacencyList[vertex].size();

    // ������� ��� ����, ��������� � ��������
    for (size_t neighbor : adjacencyList[vertex]) {
        adjacencyList[neighbor].erase(vertex);
        if (directed) {
            --numOfEdges; // ��������� ������ ���� �����������
        }
    }

    adjacencyList.erase(adjacencyList.begin() + vertex);
    --numOfVertices;

    // ������������ ������� ���������� ������
    for (auto& neighbors : adjacencyList) {
        std::set<size_t> updatedNeighbors;
        for (auto neighbor : neighbors) {
            if (neighbor == vertex) {
                continue;
            }
            if (neighbor > vertex) {
                --neighbor;
            }
            updatedNeighbors.insert(neighbor);
        }
        neighbors = std::move(updatedNeighbors);
    }
}


// ��������� ������ ������� ������
std::vector<size_t> AdjacencyListGraph::getAdjVertices(size_t vertex) const {
    if (vertex >= numOfVertices) {
        std::cerr << "Index out of range" << std::endl;
        return {};
    }
    return std::vector<size_t>(adjacencyList[vertex].begin(), adjacencyList[vertex].end());
}

// ��������� ���������� ������
size_t AdjacencyListGraph::getNumberOfVertices() const {
    return numOfVertices;
}

// ��������� ���������� ����
size_t AdjacencyListGraph::getNumberOfEdges() const {
    return numOfEdges;
}

// ����� �����
void AdjacencyListGraph::printGraph() const {
    for (size_t i = 0; i < getNumberOfVertices(); ++i) {
        std::cout << i << ": ";
        for (size_t neighbor : getAdjVertices(i)) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}
