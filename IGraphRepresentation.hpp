#pragma once

#include <vector>
#include <cstddef>

class IGraphRepresentation {
public:
    virtual ~IGraphRepresentation() = default;                              // ����������� ����������

    virtual void addEdge(size_t src, size_t dst) = 0;                       // ���������� ����� � ����
    virtual void removeEdge(size_t src, size_t dst) = 0;                    // �������� ����� �� �����
    virtual bool hasEdge(size_t src, size_t dst) const = 0;                 // �������� �� ������� ����� � �����
    virtual void addVertex() = 0;                                           // ���������� ������� � ����
    virtual void removeVertex(size_t vertex) = 0;                           // �������� ������� �� �����
    virtual std::vector<size_t> getAdjVertices(size_t vertex) const = 0;    // ��������� ������� ������� ������
    virtual size_t getNumberOfVertices() const = 0;                         // ��������� ���������� ������ � �����
    virtual size_t getNumberOfEdges() const = 0;                            // ��������� ���������� ���� � �����
    virtual void printGraph() const = 0;                                    // ����� ����� � �������
};
