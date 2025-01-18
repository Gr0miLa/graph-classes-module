#include <iostream>
#include <vector>

#include "Algorithms.hpp"

#include "Graph.hpp"

#include "CycleGraph.hpp"
#include "PathGraph.hpp"
#include "BipartiteGraph.hpp"
#include "GeneralizedPetersenGraph.hpp"
#include "DoubleGeneralizedPetersenGraph.hpp"
#include "CompleteGraph.hpp"
#include "BinaryTreeGraph.hpp"
#include "TernaryTreeGraph.hpp"
#include "StarGraph.hpp"
#include "WheelGraph.hpp"
#include "RandomGraph.hpp"

void testGraphTypes() {
    // Тест графа, заданного матрицей смежности для неориентированного графа
    std::cout << "\nA graph test given by an adjacency matrix for an undirected graph\n";
    Graph graph(5, Graph::RepresentationType::MATRIX, Graph::GraphType::UNDIRECTED);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);

    std::cout << "Number of vertices: " << graph.getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << graph.getNumberOfEdges() << "\n";

    std::cout << "Adjacency matrix for graph:\n";
    std::cout << "- - - - - - - - - -\n";
    graph.printGraph();
    std::cout << "- - - - - - - - - -\n";

    graph.addVertex();
    graph.addEdge(5, 2);
    graph.addEdge(2, 5);

    std::cout << "After adding edges to the new vertex:\n";
    std::cout << "Number of edges: " << graph.getNumberOfEdges() << "\n";

    graph.removeVertex(3);
    std::cout << "After removing vertex 3:\n";
    std::cout << "Number of vertices: " << graph.getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << graph.getNumberOfEdges() << "\n";

    std::cout << "Adjacency matrix for graph:\n";
    std::cout << "- - - - - - - - - -\n";
    graph.printGraph();
    std::cout << "- - - - - - - - - -\n";


    // Тест графа, заданного списками смежности для ориентированного графа
    std::cout << "\nA graph test given by adjacency lists for a directed graph\n";
    Graph graph2(5, Graph::RepresentationType::LIST, Graph::GraphType::DIRECTED);

    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(1, 3);
    graph2.addEdge(3, 4);
    graph2.addEdge(4, 0);

    std::cout << "Number of vertices: " << graph2.getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << graph2.getNumberOfEdges() << "\n";

    std::cout << "Adjacency matrix for graph:\n";
    std::cout << "- - - - - - - - - -\n";
    graph2.printGraph();
    std::cout << "- - - - - - - - - -\n";

    graph2.addVertex();
    graph2.addEdge(5, 2);
    graph2.addEdge(2, 5);

    std::cout << "After adding edges to the new vertex:\n";
    std::cout << "Number of edges: " << graph2.getNumberOfEdges() << "\n";

    graph2.removeVertex(3);
    std::cout << "After removing vertex 3:\n";
    std::cout << "Number of vertices: " << graph2.getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << graph2.getNumberOfEdges() << "\n";

    std::cout << "Adjacency matrix for graph:\n";
    std::cout << "- - - - - - - - - -\n";
    graph2.printGraph();
    std::cout << "- - - - - - - - - -\n";
}

void testGraphClasses() {
    // Цикл из 5 вершин
    CycleGraph cycle(5, Graph::RepresentationType::LIST);
    std::cout << "\nCycle graph: " << cycle.getName() << "\n";
    std::cout << "Number of vertices: " << cycle.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << cycle.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    cycle.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Путь из 5 вершин
    PathGraph path(5, Graph::RepresentationType::LIST);
    std::cout << "\nPath graph: " << path.getName() << "\n";
    std::cout << "Number of vertices: " << path.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << path.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    path.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Двудольный граф из 5 вершин
    std::vector<size_t> set1 = { 0, 1, 2 };
    std::vector<size_t> set2 = { 3, 4 };
    BipartiteGraph bipartite(set1, set2, Graph::RepresentationType::LIST);
    std::cout << "\nBipartite graph: " << bipartite.getName() << "\n";
    std::cout << "Number of vertices: " << bipartite.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << bipartite.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    bipartite.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Обобщённый граф Петерсена n = 5, k = 2
    GeneralizedPetersenGraph petersen(5, 2, Graph::RepresentationType::LIST);
    std::cout << "\nGeneralized Petersen graph: " << petersen.getName() << "\n";
    std::cout << "Number of vertices: " << petersen.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << petersen.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    petersen.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Двойной обобщённый граф Петерсена n = 5, k = 2
    DoubleGeneralizedPetersenGraph doublePetersen(3, 1, Graph::RepresentationType::LIST);
    std::cout << "\nDouble generalized Petersen graph: " << doublePetersen.getName() << "\n";
    std::cout << "Number of vertices: " << doublePetersen.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << doublePetersen.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    doublePetersen.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Полный граф из 5 вершин
    CompleteGraph complete(5, Graph::RepresentationType::LIST);
    std::cout << "\nComplete graph: " << complete.getName() << "\n";
    std::cout << "Number of vertices: " << complete.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << complete.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    complete.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Граф бинарное дерево из 6 вершин
    BinaryTreeGraph binaryTree(6, Graph::RepresentationType::LIST);
    std::cout << "\nBinary tree graph: " << binaryTree.getName() << "\n";
    std::cout << "Number of vertices: " << binaryTree.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << binaryTree.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    binaryTree.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Граф 3-дерево из 9 вершин
    TernaryTreeGraph ternaryTree(9, Graph::RepresentationType::LIST);
    std::cout << "\nTernary tree graph: " << ternaryTree.getName() << "\n";
    std::cout << "Number of vertices: " << ternaryTree.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << ternaryTree.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    ternaryTree.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Граф звезда с 5 вершинами
    StarGraph star(6, Graph::RepresentationType::LIST);
    std::cout << "\nStar graph: " << star.getName() << "\n";
    std::cout << "Number of vertices: " << star.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << star.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    star.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Граф колесо с 6 вершинами
    WheelGraph wheel(6, Graph::RepresentationType::LIST);
    std::cout << "\nWheel graph: " << wheel.getName() << "\n";
    std::cout << "Number of vertices: " << wheel.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << wheel.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    wheel.printGraph();
    std::cout << "- - - - - - - - - -\n";

    // Случайный граф с 6 вершинами и 10 рёбрами
    RandomGraph random(6, 10);
    std::cout << "\nRandom graph: " << random.getName() << "\n";
    std::cout << "Number of vertices: " << random.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << random.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    random.printGraph();
    std::cout << "- - - - - - - - - -\n";
}

void testGraphAlgorithms() {
    // Обобщённый граф Петерсена n = 5, k = 2
    GeneralizedPetersenGraph petersen(5, 2, Graph::RepresentationType::LIST);

    std::cout << "\nGeneralized Petersen graph: " << petersen.getName() << "\n";
    /*std::cout << "Number of vertices: " << petersen.getGraph().getNumberOfVertices() << "\n";
    std::cout << "Number of edges: " << petersen.getGraph().getNumberOfEdges() << "\n";
    std::cout << "- - - - - - - - - -\n";
    petersen.printGraph();
    std::cout << "- - - - - - - - - -\n";*/

    std::cout << "P(5, 2) algorithms\n\n";

    // Графы Петерсена с хроматическим числом 3 и n = 5
    std::vector<size_t> petersenColors = alg::colorGraph(petersen.getGraph());
    std::cout << "Colors: ";
    for (auto& elem : petersenColors) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::cout << "Chromatic Number: " << alg::chromaticNumber(petersenColors) << "\n";

    std::vector<size_t> petersenDFS = alg::dfs(petersen.getGraph(), 0);
    std::cout << "DFS: ";
    for (auto& elem : petersenDFS) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::vector<size_t> petersenBFS = alg::bfs(petersen.getGraph(), 0);
    std::cout << "BFS: ";
    for (auto& elem : petersenBFS) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::vector<std::vector<size_t>> clique = alg::findMaximalCliques(petersen.getGraph());
    std::cout << "Cliques:\n";
    for (auto& clq : clique) {
        std::cout << "[";
        for (auto& elem : clq) {
            std::cout << elem << ", ";
        }
        std::cout << "]; ";
    }
    std::cout << "\n";
    std::cout << "Max clique size: " << clique[0].size() << "\n";

    std::vector<size_t> distances = alg::dijkstra(petersen.getGraph(), 0);
    std::cout << "Distances:\n";
    for (auto& distance : distances) {
        std::cout << distance << " ";
    }
    std::cout << "\n";
    
}

int main() {
    // Тест типов графов
    std::cout << "* * * * * * * * * * * * * * * * Graph Type Test * * * * * * * * * * * * * * * *\n";
    testGraphTypes();

    // Тест классов графов
    std::cout << "\n* * * * * * * * * * * * * * * * Graph Class Test * * * * * * * * * * * * * * * *\n";
    testGraphClasses();

    // Тест алгоритмов
    std::cout << "\n* * * * * * * * * * * * * * * * Algorithm Test * * * * * * * * * * * * * * * *\n";
    testGraphAlgorithms();

    return 0;
}
