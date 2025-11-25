
#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n; // number of vertices (0..n-1)
    bool directed;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

    Graph(int n_, bool directed_) : n(n_), directed(directed_) {
        adjList.assign(n, {});
        adjMatrix.assign(n, vector<int>(n, 0));
    }

    // Add an edge u->v (0-indexed)
    void addEdge(int u, int v) {
        if (u < 0 || u >= n || v < 0 || v >= n) return;
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1; // store 1 for presence, could be weight in extensions
        if (!directed) {
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    // Check adjacency u -> v
    bool isAdjacent(int u, int v) const {
        if (u < 0 || u >= n || v < 0 || v >= n) return false;
        return adjMatrix[u][v] != 0;
    }

    // Return list of neighbors for vertex u (outgoing for directed)
    vector<int> neighbors(int u) const {
        if (u < 0 || u >= n) return {};
        return adjList[u];
    }

    // Degree for undirected graph
    int degree(int u) const {
        if (directed) {
            cerr << "Warning: degree() is for undirected graphs. Use indegree/outdegree for directed graphs.\n";
        }
        if (u < 0 || u >= n) return 0;
        return (int)adjList[u].size();
    }

    // Out-degree (for directed or interpret as degree in undirected)
    int outDegree(int u) const {
        if (u < 0 || u >= n) return 0;
        return (int)adjList[u].size();
    }

    // In-degree (for directed graph) — compute from matrix or list
    int inDegree(int u) const {
        if (u < 0 || u >= n) return 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += adjMatrix[i][u] != 0;
        return cnt;
    }

    // Number of edges
    int edgeCount() const {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adjMatrix[i][j]) ++cnt;
        if (!directed) cnt /= 2;
        return cnt;
    }

    // Print adjacency list
    void printAdjList() const {
        cout << "Adjacency List:\n";
        for (int i = 0; i < n; ++i) {
            cout << i+1 << ":";
            for (int v : adjList[i]) cout << " " << v+1;
            cout << '\n';
        }
    }

    // Print adjacency matrix
    void printAdjMatrix() const {
        cout << "Adjacency Matrix:\n   ";
        for (int j = 0; j < n; ++j) cout << setw(3) << j+1;
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << setw(3) << i+1;
            for (int j = 0; j < n; ++j) cout << setw(3) << adjMatrix[i][j];
            cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Graph Representation (Adjacency Matrix + Adjacency List)\n";
    int n;
    cout << "Enter number of vertices: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of vertices.\n";
        return 0;
    }

    char dirChar;
    cout << "Is the graph directed? (y/n): ";
    cin >> dirChar;
    bool directed = (dirChar == 'y' || dirChar == 'Y');

    Graph G(n, directed);

    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Now enter edges (u v) with vertices numbered 1.." << n << ".\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Edge " << i+1 << ": ";
        cin >> u >> v;
        // convert to 0-index
        if (u < 1 || u > n || v < 1 || v > n) {
            cout << "Invalid edge — ignored.\n";
            --i; // let user re-enter this edge
            continue;
        }
        G.addEdge(u-1, v-1);
    }

    // Interactive menu
    while (true) {
        cout << "\nMenu:\n"
             << "1. Print adjacency list\n"
             << "2. Print adjacency matrix\n"
             << "3. List neighbors of a vertex\n"
             << "4. Check adjacency (u -> v)\n"
             << "5. Degree / In-degree / Out-degree\n"
             << "6. Number of edges\n"
             << "7. Exit\n"
             << "Choose an option (1-7): ";
        int choice;
        if (!(cin >> choice)) break;

        if (choice == 1) {
            G.printAdjList();
        } else if (choice == 2) {
            G.printAdjMatrix();
        } else if (choice == 3) {
            int u; cout << "Vertex (1.." << n << "): "; cin >> u;
            if (u < 1 || u > n) { cout << "Invalid vertex.\n"; continue; }
            auto nbr = G.neighbors(u-1);
            cout << "Neighbors of " << u << ":";
            for (int v : nbr) cout << " " << v+1;
            cout << '\n';
        } else if (choice == 4) {
            int u, v; cout << "u v (1.." << n << "): "; cin >> u >> v;
            if (u < 1 || u > n || v < 1 || v > n) { cout << "Invalid vertices.\n"; continue; }
            cout << (G.isAdjacent(u-1, v-1) ? "Yes\n" : "No\n");
        } else if (choice == 5) {
            int u; cout << "Vertex (1.." << n << "): "; cin >> u;
            if (u < 1 || u > n) { cout << "Invalid vertex.\n"; continue; }
            if (!directed) {
                cout << "Degree of vertex " << u << " = " << G.degree(u-1) << '\n';
            } else {
                cout << "Out-degree of vertex " << u << " = " << G.outDegree(u-1) << '\n';
                cout << "In-degree  of vertex " << u << " = " << G.inDegree(u-1) << '\n';
            }
        } else if (choice == 6) {
            cout << "Number of edges = " << G.edgeCount() << '\n';
        } else if (choice == 7) {
            cout << "Exiting.\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
