#include "BinaryTreeGraph.hpp"

// Конструктор для создания графа бинарного дерева
BinaryTreeGraph::BinaryTreeGraph(size_t vertices, 
    Graph::RepresentationType repType, Graph::GraphType graphType)
    : graph(vertices, repType, graphType) {
    if (vertices == 0) {
        throw std::invalid_argument("Binary tree must have at least one vertex.");
    }
    buildBinaryTree(0, vertices);
}

// Метод для построения бинарного дерева
void BinaryTreeGraph::buildBinaryTree(size_t current, size_t maxVertices) {
    size_t leftChild = 2 * current + 1;
    size_t rightChild = 2 * current + 2;

    if (leftChild < maxVertices) {
        graph.addEdge(current, leftChild);
        buildBinaryTree(leftChild, maxVertices);
    }

    if (rightChild < maxVertices) {
        graph.addEdge(current, rightChild);
        buildBinaryTree(rightChild, maxVertices);
    }
}

// Получение базового графа
const Graph& BinaryTreeGraph::getGraph() const {
    return graph;
}

// Вывод цикла на консоль
void BinaryTreeGraph::printGraph() const {
    graph.printGraph();
}

// Получение обозначения графа
std::string BinaryTreeGraph::getName() const {
    return "2-Tree(" + std::to_string(graph.getNumberOfVertices()) + ")";
}
