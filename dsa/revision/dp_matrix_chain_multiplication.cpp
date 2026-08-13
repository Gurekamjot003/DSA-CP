#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

// Function to find the minimum number of scalar multiplications needed
// to multiply a chain of matrices.
// Time Complexity: O(N^3) where N is the number of matrices.
// Space Complexity: O(N^2) for the dp table.
int matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices (A1, A2, ..., An)
                             // dims array has n+1 elements: p0, p1, ..., pn
                             // Matrix Ai has dimensions dims[i-1] x dims[i]

    // dp[i][j] will store the minimum number of scalar multiplications
    // needed to compute the matrix product A_i * A_{i+1} * ... * A_j.
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is the chain length. We start with chains of length 2.
    // A chain of length 1 (e.g., A_i) requires 0 multiplications,
    // which is already handled by initializing dp table with 0.
    for (int L = 2; L <= n; ++L) {
        // i is the starting index of the matrix chain.
        // The chain is from A_i to A_j.
        for (int i = 0; i < n - L + 1; ++i) {
            int j = i + L - 1; // j is the ending index of the matrix chain.

            // Initialize dp[i][j] to a very large value.
            dp[i][j] = INT_MAX;

            // k is the split point. We try all possible split points
            // to find the minimum cost.
            // The chain A_i...A_j is split into A_i...A_k and A_{k+1}...A_j.
            // The dimensions involved are dims[i], dims[k+1], dims[j+1].
            // Note: Matrix A_x corresponds to dims[x] and dims[x
            for (int k = i; k < j; ++k) {
                // cost = (cost of A_i...A_k) + (cost of A_{k+1}...A_j) + (cost of multiplying results)
                // The dimensions for multiplying the two resulting matrices are dims[i], dims[k+1], dims[j+1].
                // For example, if we split A_i...A_j at k, we multiply (A_i...A_k) and (A_{k+1}...A_j).
                // The first matrix has dimensions dims[i] x dims[k+1].
                // The second matrix has dimensions dims[k+1] x dims[j+1].
                // The cost of multiplying these two is dims[i] * dims[k+1] * dims[j+1].
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The minimum cost for the entire chain A_0...A_{n-1} is stored in dp[0][n-1].
    return dp[0][n - 1];
}

int main() {
    // Example usage:
    // Dimensions: 10x30, 30x5, 5x60
    // This represents 3 matrices: A1(10x30), A2(30x5), A3(5x60)
    // The dims array should be {10, 30, 5, 60}
    vector<int> dims1 = {10, 30, 5, 60};
    cout << "Minimum scalar multiplications for dims1: " << matrixChainMultiplication(dims1) << endl; // Expected: 4500

    // Dimensions: 40x20, 20x30, 30x10, 10x30
    vector<int> dims2 = {40, 20, 30, 10, 30};
    cout << "Minimum scalar multiplications for dims2: " << matrixChainMultiplication(dims2) << endl; // Expected: 26000

    // Dimensions: 1x2, 2x3, 3x4
    vector<int> dims3 = {1, 2, 3, 4};
    cout << "Minimum scalar multiplications for dims3: " << matrixChainMultiplication(dims3) << endl; // Expected: 18

    return 0;
}
