#pragma once

#include "Graph.hpp"
#include "GeneralizedPetersenGraph.hpp"
#include "DoubleGeneralizedPetersenGraph.hpp"
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>

namespace alg {
    // Раскраска графа
    std::vector<size_t> colorGraph(const Graph& graph) {
        size_t V = graph.getNumberOfVertices();
        std::vector<int> listVertex;
        std::vector<int> colors;
        std::map<int, int> colorMap;

        for (size_t i = 0; i < V; ++i) {
            std::vector<size_t> adj = graph.getAdjVertices(i);
            listVertex.push_back(adj.size());
            colors.push_back(i);
            colorMap[i] = -1;
        }

        std::sort(listVertex.begin(), listVertex.end(), std::greater<int>());

        colorMap[0] = 0;

        for (auto color : colors) {
            for (int i = 0; i < V; ++i) {
                if (colorMap[i] == -1) {
                    bool skip = false;
                    for (auto vertex : graph.getAdjVertices(i)) {
                        if (colorMap[vertex] == color) {
                            skip = true;
                            break;
                        }
                    }
                    if (!skip)
                        colorMap[i] = color;
                }
            }
        }

        std::vector<size_t> result;
        for (size_t i = 0; i < V; ++i) {
            result.push_back(colorMap[i]);
        }

        return result;
    }

    // Поиск хроматического числа
    size_t chromaticNumber(std::vector<size_t> colors) {
        std::sort(colors.begin(), colors.end());

        size_t count = 1;

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] != colors[i - 1]) {
                ++count;
            }
        }
        return count;
    }

    // Алгоритм обхода графа в глубину (DFS)
    std::vector<size_t> dfs(const Graph& graph, size_t startVertex) {
        std::vector<size_t> result;
        std::vector<bool> visited(graph.getNumberOfVertices(), false);
        std::stack<size_t> stack;

        stack.push(startVertex);

        while (!stack.empty()) {
            size_t vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                result.push_back(vertex);

                for (size_t adjVertex : graph.getAdjVertices(vertex)) {
                    if (!visited[adjVertex]) {
                        stack.push(adjVertex);
                    }
                }
            }
        }

        return result;
    }

    // Алгоритм обхода графа в ширину (BFS)
    std::vector<size_t> bfs(const Graph& graph, size_t startVertex) {
        std::vector<size_t> result;
        std::vector<bool> visited(graph.getNumberOfVertices(), false);
        std::queue<size_t> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            size_t vertex = queue.front();
            queue.pop();
            result.push_back(vertex);

            for (size_t adjVertex : graph.getAdjVertices(vertex)) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push(adjVertex);
                }
            }
        }

        return result;
    }

    // Алгоритм Брона Кербоша
    void bronKerbosch(const Graph& graph, std::vector<size_t>& R, std::set<size_t>& P, 
        std::set<size_t>& X, std::vector<std::vector<size_t>>& cliques) {
        if (P.empty() && X.empty()) {
            cliques.push_back(R);
            return;
        }

        std::set<size_t> P_copy = P;
        for (size_t v : P_copy) {
            std::vector<size_t> nextR = R;
            nextR.push_back(v);
            std::set<size_t> nextP;
            std::set<size_t> nextX;

            std::vector<size_t> neighbors = graph.getAdjVertices(v);
            for (size_t neighbor : neighbors) {
                if (P.count(neighbor))
                    nextP.insert(neighbor);
                if (X.count(neighbor))
                    nextX.insert(neighbor);
            }

            bronKerbosch(graph, nextR, nextP, nextX, cliques);

            P.erase(v);
            X.insert(v);
        }
    }

    // Поиск клик
    std::vector<std::vector<size_t>> findMaximalCliques(const Graph& graph) {
        std::vector<std::vector<size_t>> cliques;
        std::vector<size_t> R;
        std::set<size_t> P;
        std::set<size_t> X;

        for (size_t i = 0; i < graph.getNumberOfVertices(); ++i) {
            P.insert(i);
        }

        bronKerbosch(graph, R, P, X, cliques);
        return cliques;
    }

    // Алгоритм Дейкстры
    std::vector<size_t> dijkstra(const Graph& graph, size_t startVertex) {
        size_t numVertices = graph.getNumberOfVertices();
        std::vector<size_t> distances(numVertices, std::numeric_limits<size_t>::max());
        std::vector<bool> visited(numVertices, false);
        using Pair = std::pair<size_t, size_t>; // расстояние, вершина
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> priorityQueue;

        distances[startVertex] = 0;
        priorityQueue.emplace(0, startVertex);

        while (!priorityQueue.empty()) {
            size_t currentDistance = priorityQueue.top().first;
            size_t currentVertex = priorityQueue.top().second;
            priorityQueue.pop();

            if (visited[currentVertex]) {
                continue;
            }
            visited[currentVertex] = true;

            for (size_t neighbor : graph.getAdjVertices(currentVertex)) {
                size_t edgeWeight = 1; // По умолчанию вес ребра равен 1
                size_t newDistance = currentDistance + edgeWeight;

                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    priorityQueue.emplace(newDistance, neighbor);
                }
            }
        }

        return distances;
    }
}  // namespace alg
