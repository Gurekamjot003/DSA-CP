//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int solve(vector<int>& wt, vector<int>& val, int capacity, vector<vector<int>>& dp, int curwt = 0, int index = 0){
        
        if(curwt>capacity) return INT_MIN;
        if(index>= val.size()) return 0;
        if(dp[curwt][index] != -1) return dp[curwt][index];
        return dp[curwt][index] = max(solve(wt, val, capacity,  dp, curwt, index + 1), 
            val[index] + solve(wt, val, capacity, dp, curwt + wt[index],  index+1));
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(capacity+1, vector<int>(val.size() + 1, -1));
        return solve(wt, val, capacity, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends