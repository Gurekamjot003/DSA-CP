// DSU (Disjoint Set Union) or Union-Find data structure

#include <numeric> // For std::iota
#include <vector>

class DSU {
    std::vector<int> parent; // parent[i] stores the parent of element i
    std::vector<int> sz;     // sz[i] stores the size of the set if i is the representative

public:
    // Constructor: Initializes n disjoint sets, each containing one element
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Each element is its own parent initially
        sz.assign(n, 1);                             // Each set initially has size 1
    }

    // Find operation with path compression: Returns the representative (root) of the set containing i
    int find(int i) {
        if (parent[i] == i) {
            return i; // If i is its own parent, it's the representative
        }
        // Path compression: Set parent[i] directly to the root
        return parent[i] = find(parent[i]);
    }

    // Union operation by size: Merges the sets containing i and j
    // Returns true if a union occurred (i.e., i and j were in different sets), false otherwise
    bool unite(int i, int j) {
        int root_i = find(i); // Find representative of i
        int root_j = find(j); // Find representative of j

        if (root_i != root_j) {
            // If they are in different sets, merge them
            // Union by size: Attach the smaller tree under the root of the larger tree
            if (sz[root_i] < sz[root_j]) {
                std::swap(root_i, root_j); // Ensure root_i is the larger or equal sized tree
            }
            parent[root_j] = root_i;     // Make root_i the parent of root_j
            sz[root_i] += sz[root_j];    // Update the size of the new merged set
            return true; // Union successful
        }
        return false; // Already in the same set, no
    }
};
    