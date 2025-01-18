#include "GeneralizedPetersenGraph.hpp"

GeneralizedPetersenGraph::GeneralizedPetersenGraph(size_t _n, size_t _k,
	Graph::RepresentationType repType, Graph::GraphType graphType)
	: graph(2 * _n, repType, graphType), n(_n), k(_k) {
	if ((n < (2 * k + 1)) || ((2 * k + 1) < 3)) {
		throw std::invalid_argument("Invalid argument");
	}
	for (size_t i = 0; i < n; ++i) {
		graph.addEdge(i, ((i + 1) % n));
		graph.addEdge(i, i + n);
		graph.addEdge(i + n, ((i + k) % n) + n);
	}
}

const Graph& GeneralizedPetersenGraph::getGraph() const {
	return graph;
}

void GeneralizedPetersenGraph::printGraph() const {
	graph.printGraph();
}

// Получение обозначения графа
std::string GeneralizedPetersenGraph::getName() const {
	return "P(" + std::to_string(n) + ", " + std::to_string(k) + ")";
}
