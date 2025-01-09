#pragma once
#include "Graph.hpp"
#include <string>

class GeneralizedPetersenGraph {
private:
	Graph graph;
	size_t n;
	size_t k;

public:
	GeneralizedPetersenGraph(size_t n, size_t k,
		Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

	const Graph& getGraph() const;
	void printGraph() const;
	std::string getName() const;
};
