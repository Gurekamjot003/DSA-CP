#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    vector<vector<int>> heights;
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<vector<bool>> visited;
    bool can_pacific(int i, int j, int prev_height = INT_MAX){
        if(i<0 or j<0) return true;
        if(i==n or j == m) return false;

        if(heights[i][j] > prev_height) return false;
        if(visited[i][j]) return pacific[i][j];
        visited[i][j] = true;

        bool ans = false;
        ans |= can_pacific(i, j-1, heights[i][j]);
        ans |= can_pacific(i, j+1, heights[i][j]);
        ans |= can_pacific(i-1, j, heights[i][j]);
        ans |= can_pacific(i+1, j, heights[i][j]);

        return pacific[i][j] = ans;
    }    
    bool can_atlantic(int i, int j, int prev_height = INT_MAX){
        if(i<0 or j<0) return false;
        if(i==n or j == m) return true;

        if(heights[i][j] > prev_height) return false;
        if(visited[i][j]) return atlantic[i][j];
        visited[i][j] = true;

        bool ans = false;
        ans |= can_atlantic(i, j-1, heights[i][j]);
        ans |= can_atlantic(i, j+1, heights[i][j]);
        ans |= can_atlantic(i-1, j, heights[i][j]);
        ans |= can_atlantic(i+1, j, heights[i][j]);

        return atlantic[i][j] = ans;
    }    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        this->heights = heights;
        pacific.resize(n, vector<bool>(m));
        atlantic.resize(n, vector<bool>(m));
        visited.resize(n, vector<bool>(m));
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(can_pacific(i, j) && can_atlantic(i,j)) ans.push_back({i, j});
            }
        }
       
        return ans;
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}};
    Solution sol;
    sol.pacificAtlantic(heights);
}