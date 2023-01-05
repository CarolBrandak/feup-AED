// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <bits/stdc++.h>

using namespace std;

typedef stack<int> si;
typedef list<int> li;
typedef list<li> lli;

class Graph {
public:
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        bool inStack;   // Is the node in the stack?
        char color;
        int low;
        int num;
        int parent;
        int cost;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);
    bool dfs_bipartite(int v, char color);
    int dfs_count_scc(int v, int &order);

    // ----- Functions to implement in this class -----
    bool bipartite();
    int countSCCs();
    list<list<int>> listSCCs();
    list<int> articulationPoints();

    int dfs_count_scc(int v, int &order, si &s);

    void dfs_list_scc(int v, int &order, si &s, lli &l);

    void dfs_articulation_points(int v, int &order, li &l);
};

#endif
