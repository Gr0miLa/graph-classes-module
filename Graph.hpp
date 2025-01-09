#pragma once

#include <memory>
#include <vector>
#include "IGraphRepresentation.hpp"
#include <iostream>

class Graph {
public:
    enum class RepresentationType { MATRIX, LIST };         // ������ ������������ �����
    enum class GraphType { DIRECTED, UNDIRECTED };          // ��� �����

    Graph(size_t vertices, RepresentationType repType, 
        GraphType graphType);                               // �����������
    Graph(Graph&& other) noexcept;                          // ����������� �����������
    Graph& operator=(Graph&& other) noexcept;               // �������� �����������
    ~Graph() = default;                                     // ���������� �� ���������

    void addEdge(size_t src, size_t dst);                   // ���������� ����� � ����
    void removeEdge(size_t src, size_t dst);                // �������� ����� �� �����
    bool hasEdge(size_t src, size_t dst) const;             // �������� �� ������� ����� � �����
    void addVertex();                                       // ���������� ������� � ����
    void removeVertex(size_t vertex);                       // �������� ������� �� �����
    std::vector<size_t> getAdjVertices(size_t vertex) const;// ��������� ������� ������� ������
    size_t getNumberOfVertices() const;                     // ��������� ���������� ������ � �����
    size_t getNumberOfEdges() const;                        // ��������� ���������� ���� � �����
    void printGraph() const;                                // ����� ����� � �������

private:
    std::unique_ptr<IGraphRepresentation> representation;   // ������������� �����
    GraphType graphType;                                    // ��� �����
};
