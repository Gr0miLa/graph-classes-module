#include "Graph.hpp"
#include "AdjacencyMatrixGraph.hpp"
#include "AdjacencyListGraph.hpp"

// Конструктор: выбирает представление графа и тип (ориентированный/неориентированный)
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

// Конструктор перемещения
Graph::Graph(Graph&& other) noexcept
    : representation(std::move(other.representation)),
    graphType(other.graphType) {}

// Оператор перемещения
Graph& Graph::operator=(Graph&& other) noexcept {
    if (this != &other) {
        // Сначала освобождаем ресурсы текущего объекта
        // std::unique_ptr освобождается автоматически, так что достаточно переместить новый объект

        representation = std::move(other.representation); // Перемещаем уникальный указатель
        graphType = other.graphType; // Копируем тип графа
    }
    return *this;
}

// Добавление ребра
void Graph::addEdge(size_t src, size_t dst) {
    representation->addEdge(src, dst);
}

// Удаление ребра
void Graph::removeEdge(size_t src, size_t dst) {
    representation->removeEdge(src, dst);
}

// Проверка на наличие ребра
bool Graph::hasEdge(size_t src, size_t dst) const {
    return representation->hasEdge(src, dst);
}

// Добавление вершины
void Graph::addVertex() {
    representation->addVertex();
}

// Удаление вершины
void Graph::removeVertex(size_t vertex) {
    representation->removeVertex(vertex);
}

// Вывод графа
void Graph::printGraph() const {
    return representation->printGraph();
}

// Получение смежных вершин
std::vector<size_t> Graph::getAdjVertices(size_t vertex) const {
    return representation->getAdjVertices(vertex);
}

// Получение количества вершин
size_t Graph::getNumberOfVertices() const {
    return representation->getNumberOfVertices();
}

// Получение количества рёбер
size_t Graph::getNumberOfEdges() const {
    return representation->getNumberOfEdges();
}
