#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> rev_adj; // Reversed adjacency list
    vector<bool> visited; // To keep track of visited vertices
    stack<int> s; // Stack to store vertices in order of finishing times

public:
    Graph(int V) : V(V), adj(V), rev_adj(V), visited(V, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // Add edge to reversed graph
    }

    // DFS for the first pass (filling the stack)
    void fillOrder(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                fillOrder(v);
            }
        }
        s.push(u);
    }

    // DFS for the second pass (finding SCCs)
    void findSCCsDFS(int u) {
        visited[u] = true;
        cout << u << " ";
        for (int v : rev_adj[u]) {
            if (!visited[v]) {
                findSCCsDFS(v);
            }
        }
    }

    void findSCCs() {
        // Step 1: Fill vertices in stack according to their finishing times
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                fillOrder(i);
            }
        }

        // Step 2: Mark all vertices as not visited for the second DFS
        fill(visited.begin(), visited.end(), false);

        // Step 3: Process all vertices in order defined by stack
        cout << "Strongly Connected Components are:\n";
        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (!visited[u]) {
                findSCCsDFS(u);
                cout << endl;
            }
        }
    }
};

int main() {
    // Create a graph given in the example
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.findSCCs();

    cout << endl;

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    g2.findSCCs();

    cout << endl;

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

    g3.findSCCs();

    return 0;
}