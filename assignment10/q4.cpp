#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find)
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;

        if (rank[x] == rank[y]) rank[x]++;

        return true;
    }
};

// Edge structure
struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<Edge> edges(m);

    cout << "Enter edges as (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;  // convert to 0-index
        edges[i].v--;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;

    // Kruskal's Algorithm
    for (Edge &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
        }
    }

    // Output MST
    cout << "\nMinimum Spanning Tree (Kruskal):\n";
    for (auto &e : mst) {
        cout << e.u + 1 << " -- " << e.v + 1 << "  (weight " << e.w << ")\n";
    }
    cout << "Total Minimum Weight = " << totalWeight << "\n";

    return 0;
}
