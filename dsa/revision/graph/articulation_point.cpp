#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<int> disc_time; // Discovery times of visited vertices
    vector<int> low; // Lowest discovery time reachable from subtree rooted at current vertex
    vector<bool> visited; // To keep track of visited vertices
    vector<bool> is_articulation_point; // To mark articulation points
    int timer; // Global timer for discovery times

public:
    Graph(int V) : V(V), adj(V), disc_time(V, -1), low(V, -1), visited(V, false), is_articulation_point(V, false), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For an undirected graph
    }

    void findArticulationPointsDFS(int u, int p = -1) {
        visited[u] = true;
        disc_time[u] = low[u] = timer++;
        int children = 0; // Count of children in DFS tree

        for (int v : adj[u]) {
            if (v == p) continue; // Skip parent

            if (visited[v]) {
                // Back-edge found
                low[u] = min(low[u], disc_time[v]);
            } else {
                // Tree-edge found
                findArticulationPointsDFS(v, u);
                low[u] = min(low[u], low[v]);
                children++;

                // Case 1: u is root of DFS tree and has more than one child
                if (p == -1 && children > 1) {
                    is_articulation_point[u] = true;
                }
                // Case 2: u is not root and low[v] >= disc_time[u]
                if (p != -1 && low[v] >= disc_time[u]) {
                    is_articulation_point[u] = true;
                }
            }
        }
    }

    vector<bool> getArticulationPoints() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                findArticulationPointsDFS(i);
            }
        }
        return is_articulation_point;
    }
};

int main() {
    // Example 1
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "Articulation points in graph 1:\n";
    vector<bool> ap1 = g1.getArticulationPoints();
    for (int i = 0; i < ap1.size(); ++i) {
        if (ap1[i]) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    // Example 2
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    cout << "Articulation points in graph 2:\n";
    vector<bool> ap2 = g2.getArticulationPoints();
    for (int i = 0; i < ap2.size(); ++i) {
        if (ap2[i]) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    // Example 3 (Disconnected graph)
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(3, 4);
    g3.addEdge(4, 5);
    g3.addEdge(5, 6);
    g3.addEdge(6, 3);
    g3.addEdge(2, 3); 
    
    cout << "Articulation points in graph 3:\n";
    vector<bool> ap3 = g3.getArticulationPoints();
    for (int i = 0; i < ap3.size(); ++i) {
        if (ap3[i]) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    return 0;
}
