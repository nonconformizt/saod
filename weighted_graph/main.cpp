#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

// <index, weight, isDangerous>
typedef tuple<int, int, bool> Edge;

class Graph {
    int V;
    list<Edge> *adj;

public:
    explicit Graph(int V);
    void addEdge(int u, int v, int w, bool isDangerous);
    list<int> safestPath(int src, int end);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<Edge>[this->V];
}

void Graph::addEdge(int u, int v, int w, bool isDangerous)
{
    adj[u].push_back({v, w, isDangerous});
    adj[v].push_back({u, w, isDangerous});
}

list<int> Graph::safestPath(int src, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
    vector<int> dist(this->V,INF);
    vector<int> prev(this->V,INF);

    dist[src] = prev[src] = 0;
    list<Edge>::iterator it;
    queue.push({0, src});

    while(!queue.empty()) {
        int u = std::get<1>(queue.top());
        queue.pop();

        for(it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = std::get<0>(*it);
            int w = std::get<1>(*it);
            bool isDanger = std::get<2>(*it);
            // учитываем длину пути только если это опасный участок
            if (!isDanger)
                w = 0;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                queue.push({dist[v], v});
            }
        }
    }
    list<int> path;
    int i = end;
    while (i != src) {
        path.push_front(i);
        i = prev[i];
    }
    path.push_front(src);
    return path;
}





int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(2, 0, 1, false);
    g.addEdge(0, 1, 6, false);
    g.addEdge(2, 1, 2, true);
    g.addEdge(2, 3, 1, false);
    g.addEdge(3, 1, 2, false);
    g.addEdge(1, 4, 5, true);
    g.addEdge(3, 4, 3, true);

    list<int> path = g.safestPath(0, 4);

    cout << "Found path: ";
    for (auto it = path.begin(); it != path.end(); ++it) {
        cout << *it;
        if (it != path.end())
            cout << " => ";
    }
    cout << endl;

    return 0;
}
