// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

bool Graph::dfs_cycle(int v) {
    nodes[v].color = 1;     // gray, visiting

    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].color == 1) return true;           // cycle found!
        if (nodes[w].color == 0)
            if (dfs_cycle(w)) return true;      // if white, visit
    }
    nodes[v].color = 2;     // black, finished dfs
    return false;
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if(!(v>n|| v<1))
        return nodes.at(v).adj.size();
    return -1;
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    int res=0;
    if(!(v>n|| v<1)){
        for (auto it =nodes[v].adj.begin(); it!=nodes[v].adj.end();it++) {
            res+=it->weight;
        }
        return res;
    }
    return -1;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int total=0;
    for ( int v=1; v<=nodes.size()-1; v++){
        if (!nodes[v].visited) {
            total++;
            dfs(v);
        }
    }
    return total;
}

// ..............................
// b) Componente gigante
// TODO
void Graph::dfs_number(int v, int &total) {
    nodes[v].visited = true;
    total++;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs_number(w, total);
    }
}

int Graph::giantComponent() {
    int max=0;
    for( auto node: nodes)
        node.visited=false;
    for (int i = 1; i < n-1; i++) {
        if (!nodes[i].visited) {
            int total=0;
            dfs_number(i, total);
            if(total>max){
                max=total;
            }
        }
    }
    return max;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
void Graph::topologicalDFS(int v, list<int> &order){
    nodes[v].visited= true;
    for (Edge e:nodes[v].adj){
        int node=e.dest;
        if(!nodes[node].visited)
            topologicalDFS(node,order);
    }
    order.push_front(v);
}

list<int> Graph::topologicalSorting() {
    list<int> order={};
    for (int i=1 ;i<=n ;i++) {
        if(!nodes[i].visited){
            topologicalDFS(i, order);
        }
    }
    return order;
}


// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    for (Node &node : nodes) node.color = 0;    // white!

    for (int v = 1; v <= n; v++) {
        if (nodes[v].color == 0)
            if (dfs_cycle(v)) return true;
    }
    return false;
}
