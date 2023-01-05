// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        char color;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        char color;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);

    bool dfs_cycle(int v);

    // ----- Functions to implement in this class -----
    int outDegree(int v);
    int weightedOutDegree(int v);
    int connectedComponents();
    int giantComponent();
    void dfs_number(int v, int &total);
    list<int> topologicalSorting();
    void topologicalDFS(int v, list<int> &order);
    bool hasCycle();

};

#endif