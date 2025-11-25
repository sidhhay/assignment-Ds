#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges as (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        adj[u].push_back({v, w});  // directed graph
        // For undirected graph, also add: adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source vertex (1.." << n << "): ";
    cin >> src;
    src--;

    // Distance array
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;  

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Distances from source " << src + 1 << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << " → ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
