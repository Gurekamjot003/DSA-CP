#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<int> disc_time; // Discovery times of visited vertices
    vector<int> low; // Lowest discovery time reachable from subtree rooted at current vertex
    vector<bool> visited; // To keep track of visited vertices
    int timer; // Global timer for discovery times
    vector<pair<int, int>> bridges; // Stores the bridges

public:
    Graph(int V) : V(V), adj(V), disc_time(V, -1), low(V, -1), visited(V, false), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    void findBridgesDFS(int u, int p = -1) {
        visited[u] = true;
        disc_time[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == p) continue; // Skip parent

            if (visited[v]) {
                // Back-edge found
                low[u] = min(low[u], disc_time[v]);
            } else {
                // Tree-edge found
                findBridgesDFS(v, u);
                low[u] = min(low[u], low[v]);

                // If low[v] > disc_time[u], then (u, v) is a bridge
                if (low[v] > disc_time[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

    vector<pair<int, int>> getBridges() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                findBridgesDFS(i);
            }
        }
        return bridges;
    }
};

int main() {
    // Example 1
    Graph g1(5);
    g1.addEdge(1, 2);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    
    cout << "Bridges in graph 1:\n";
    vector<pair<int, int>> bridges1 = g1.getBridges();
    for (const auto& bridge : bridges1) {
        cout << bridge.first << " -- " << bridge.second << endl;
    }
    cout << endl;

    // Example 2
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    
    cout << "Bridges in graph 2:\n";
    vector<pair<int, int>> bridges2 = g2.getBridges();
    for (const auto& bridge : bridges2) {
        cout << bridge.first << " -- " << bridge.second << endl;
    }
    cout << endl;

    // Example 3 (Disconnected graph)
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(3, 4);
    g3.addEdge(4, 5);
    g3.addEdge(5, 6);
    g3.addEdge(6, 3);
    g3.addEdge(2, 3); // This is a bridge
    
    cout << "Bridges in graph 3:\n";
    vector<pair<int, int>> bridges3 = g3.getBridges();
    for (const auto& bridge : bridges3) {
        cout << bridge.first << " -- " << bridge.second << endl;
    }
    cout << endl;

    return 0;
    
}
