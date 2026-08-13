#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<int> disc_time; // Discovery times of visited vertices
    vector<int> low; // Lowest discovery time reachable from subtree rooted at current vertex
    vector<bool> onStack; // To check if a vertex is currently in stack
    stack<int> st; // Stack to store vertices during DFS
    int timer; // Global timer for discovery times
    vector<vector<int>> sccs; // Stores the found SCCs

public:
    Graph(int V) : V(V), adj(V), disc_time(V, -1), low(V, -1), onStack(V, false), timer(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void findSCCsDFS(int u) {
        disc_time[u] = low[u] = timer++; // Initialize discovery time and low-link value
        st.push(u); // Push current vertex to stack
        onStack[u] = true; // Mark as on stack

        // Recur for all adjacent vertices
        for (int v : adj[u]) {
            if (disc_time[v] == -1) { // If v is not visited yet
                findSCCsDFS(v);
                low[u] = min(low[u], low[v]); // Propagate low-link value from child
            } else if (onStack[v]) { // If v is visited and on stack (back-edge)
                low[u] = min(low[u], disc_time[v]); // Update low-link value
            }
        }

        // If u is a root of SCC
        if (low[u] == disc_time[u]) {
            vector<int> current_scc;
            while (true) {
                int node = st.top();
                st.pop();
                onStack[node] = false;
                current_scc.push_back(node);
                if (node == u) {
                    break;                
                }
            }
            sccs.push_back(current_scc);
        }
    }

    vector<vector<int>> getSCCs() {
        for (int i = 0; i < V; ++i) {
            if (disc_time[i] == -1) { // If vertex not visited yet
                findSCCsDFS(i);
            }
        }
        return sccs;
    }
};

int main() {
    // Example 1
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(1, 3);
    g1.addEdge(3, 4);

    cout << "SCCs in graph 1:\n";
    vector<vector<int>> sccs1 = g1.getSCCs();
    for (const auto& scc : sccs1) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Example 2
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    cout << "SCCs in graph 2:\n";
    vector<vector<int>> sccs2 = g2.getSCCs();
    for (const auto& scc : sccs2) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Example 3
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);

    cout << "SCCs in graph 3:\n";
    vector<vector<int>> sccs3 = g3.getSCCs();
    for (const auto& scc : sccs3) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}