#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<string, int> mp;

        int ans = 1;
        for(int i = 0; i<n; i++){
            string cur;

            for (int j = 0; j < m; j++) {
                if (matrix[i][0] == matrix[i][j]) {
                    cur.push_back('1');
                } 
                else {
                    cur.push_back('0');
                }
            }
            mp[cur]++;
            ans = max(ans, mp[cur]);
        }

        return ans;
    }
};