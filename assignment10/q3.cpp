#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int n;                     // number of vertices
    bool directed;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> startTime, finishTime;
    int timer;

    Graph(int n, bool directed = false) {
        this->n = n;
        this->directed = directed;
        adj.resize(n);
        visited.resize(n, false);
        startTime.resize(n, 0);
        finishTime.resize(n, 0);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    void DFSUtil(int u) {
        visited[u] = true;
        startTime[u] = ++timer;

        cout << u + 1 << " ";  // DFS order

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v);
            }
        }

        finishTime[u] = ++timer;
    }

    void DFS(int src) {
        fill(visited.begin(), visited.end(), false);
        timer = 0;

        cout << "DFS Traversal: ";
        DFSUtil(src);
        cout << "\n\nDiscovery & Finish Times:\n";

        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i + 1
                 << ": Start = " << startTime[i]
                 << ", Finish = " << finishTime[i] << "\n";
        }
    }
};

int main() {
    int n, m;
    char ch;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Is the graph directed? (y/n): ";
    cin >> ch;
    bool directed = (ch == 'y' || ch == 'Y');

    Graph g(n, directed);

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v) using vertices 1.." << n << ":\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);
    }

    int src;
    cout << "Enter DFS source vertex (1.." << n << "): ";
    cin >> src;

    cout << "\nPerforming DFS...\n";
    g.DFS(src - 1);

    return 0;
}
