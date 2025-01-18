#include "DoubleGeneralizedPetersenGraph.hpp"

DoubleGeneralizedPetersenGraph::DoubleGeneralizedPetersenGraph(size_t _n, size_t _k,
	Graph::RepresentationType repType, Graph::GraphType graphType)
	: graph(4 * _n, repType, graphType), n(_n), k(_k) {
	if ((n < 3) || (k < 1) || (k > n - 1)) {
		throw std::invalid_argument("Invalid argument");
	}
	for (size_t i = 0; i < n; ++i) {
		graph.addEdge(i, ((i + 1) % n));
		graph.addEdge(i, i + n);
		graph.addEdge(i + n, ((i + k) % n) + (2 * n));
		graph.addEdge(i + 2 * n, ((i + k) % n) + n);
		graph.addEdge(i + 2 * n, i + 3 * n);
		graph.addEdge(i + 3 * n, ((i + 1) % n + (3 * n)));
	}
}

const Graph& DoubleGeneralizedPetersenGraph::getGraph() const {
	return graph;
}

void DoubleGeneralizedPetersenGraph::printGraph() const {
	graph.printGraph();
}

// Получение обозначения графа
std::string DoubleGeneralizedPetersenGraph::getName() const {
	return "DP(" + std::to_string(n) + ", " + std::to_string(k) + ")";
}
