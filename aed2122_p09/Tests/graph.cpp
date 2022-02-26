// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

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
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO
int Graph::outDegree(int v) {
    if(!(v>n|| v<1))
        return nodes.at(v).adj.size();
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

    for(int i=1; i<=nodes.size()-1; i++){
        if(!nodes[i].visited){
            total++;
            dfs(i);
        }
    }
    return total;
}

// ..............................
// b) Componente gigante
// TODO
//
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
    int max=INT_MIN;
    for( auto node: nodes)
        node.visited=false;
    for(int i=1; i<=nodes.size()-1; i++){
        if(!nodes[i].visited){
            int attemp=0;
            dfs_number(i,attemp);
            max= attemp>max ? attemp: max;
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

void Graph::resetNodes() {

    for (int i = 1 ; i <= n ; i++) {
        nodes[i].visited = false;
        nodes[i].distance = 0;
        nodes[i].color = WHITE;
    }
}

list<int> Graph::topologicalSorting() {
    resetNodes();
    list<int> order={};
    for (int i=1 ;i<=n ;i++) {
        if(!nodes[i].visited){
            topologicalDFS(i, order);
        }
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO

void Graph::fillDistances(int v) {

    resetNodes();

    queue<int> visitedNodes = {};
    visitedNodes.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();
        cout << node << "->" << nodes[node].distance << " ";

        for (Edge e : nodes[node].adj) {
            int a = e.dest;
            if (!nodes[a].visited) {
                visitedNodes.push(a);
                nodes[a].visited = true;
                nodes[a].distance = nodes[node].distance + 1;
            }
        }
    }
}

int Graph::distance(int a, int b) {
    if (a == b)
        return 0;
    fillDistances(a);
    return nodes[b].distance ? nodes[b].distance : -1;
}


// ..............................
// b) Diametro
// TODO
int Graph::diameter() {
    if (connectedComponents() > 1) return -1;

    int max = INT_MIN;

    for (int i = 1 ; i <= n ; i++) {
        fillDistances(i);
        for (const Node &node : nodes) {
            max = node.distance > max ? node.distance : max;
        }
    }

    return max;
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO

bool Graph::colorsDFS(int v) {
    nodes[v].color = GRAY;
    for (Edge edge : nodes[v].adj) {
        int dest = edge.dest;
        if (nodes[dest].color == GRAY) {
            return true;
        } else {
            colorsDFS(dest);
        }
    }
    nodes[v].color = BLACK;
}

bool Graph::hasCycle() {
    resetNodes();
    for (int i = 0 ; i <= n ; i++) {
        if (nodes[i].color == WHITE) {
            bool answer = colorsDFS(i);
            if (answer) return answer; else continue;
        }
    }
    return false;
}
