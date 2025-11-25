#include <bits/stdc++.h>
using namespace std;

struct Node {
    int vertex;
    int weight;
};

// Comparator for min-heap
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;  // min-heap based on weight
    }
};

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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected graph
    }

    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    // Start from vertex 1 (index 0)
    pq.push({0, 0});  // (vertex, weight)

    int totalCost = 0;
    vector<pair<pair<int,int>, int>> mst;  
    // stores ((u,v), weight)

    while (!pq.empty()) {
        auto [u, weight] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalCost += weight;

        // Save the edge (but ignore first dummy edge)
        if (weight != 0) mst.push_back({{-1, u}, weight}); 

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!inMST[v]) {
                pq.push({v, w});
            }
        }
    }

    cout << "\nPrim’s Minimum Spanning Tree:\n";
    for (int i = 1; i < mst.size(); i++) {
        cout << "Vertex " << mst[i].first.second + 1 
             << " connected with weight " << mst[i].second << "\n";
    }

    cout << "Total Minimum Cost = " << totalCost << "\n";

    return 0;
}
