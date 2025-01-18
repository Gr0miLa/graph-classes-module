#pragma once
#include "Graph.hpp"
#include <string>

class DoubleGeneralizedPetersenGraph
{
private:
	Graph graph;
	size_t n;
	size_t k;

public:
	DoubleGeneralizedPetersenGraph(size_t n, size_t k,
		Graph::RepresentationType repType, Graph::GraphType graphType = Graph::GraphType::UNDIRECTED);

	const Graph& getGraph() const;
	void printGraph() const;
	std::string getName() const;
};
