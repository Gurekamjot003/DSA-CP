/*

grid[m][n] - non negative, int k 

0 - water 
positive - land

no of islands whose score is divisible by k

score- sum of all +ve values in island

testcase 1 - 
grid = {
        {0, 2, 1, 0, 0}, 
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0}, 
        {0, 2, 0, 0, 8}
}
k = 5
return 2

grid = {
        {3, 0, 3, 0}, 
        {0, 3, 0, 3},
        {3, 0, 3, 0},
}
k = 3
return 6


*/

#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int,int>

vector<pii> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int row_index, int col_index, vvi& grid, int k, vvb& visited, int& ans, int m, int n){

    queue<pii> q;
    q.push({row_index, col_index});
    
    int current_island_sum = 0;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        if(visited[i][j]) continue;
        visited[i][j] = true;
        current_island_sum += grid[i][j];
        for(auto&[di, dj]: directions){
            int next_i = i+di, next_j = j+dj;
            if(next_i>=0 && next_i<m && next_j>=0 && next_j<n && grid[next_i][next_j] != 0 && !visited[next_i][next_j])
                q.push({next_i, next_j});
        }
    }
    if(current_island_sum%k ==0) ans++;
}

int count_of_islands_divisible_by_k(vvi& grid, int k){
    int m = grid.size(), n = grid[0].size();
    vvb visited(m, vb(n));

    int ans = 0;
    for(int row_index = 0; row_index<m; row_index++){
        for(int col_index = 0; col_index<n; col_index++){
            if(!visited[row_index][col_index] && grid[row_index][col_index] > 0){
                bfs(row_index, col_index, grid, k, visited, ans, m ,n);
            }
        }
    }

    return ans;
}

int main(){
    vvi grid = {
        {0, 2, 1, 0, 0}, 
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0}, 
        {0, 2, 0, 0, 8}
};
    cout<<count_of_islands_divisible_by_k(grid, 5);
}