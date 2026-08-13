// The problem is to count all the possible paths on an m x n grid from top left
// (grid[O][O]) to bottom right (grid[m-1] [n-1]).
// Having constraints that from each cell you can either move only to right or
// down.
// Input: m = 2, n = 3
// Output:
// 3

#include<iostream>
#include<vector>
using namespace std;

int pathCount(int i, int j, vector<vector<int>> grid){
    if(i>=grid.size() or j>=grid[0].size()) return 0;
    if(i == grid.size()-1 && j==grid[0].size()-1){
        return 1;
    }
    return
    pathCount(i+1, j, grid) + 
    pathCount(i, j+1, grid);

}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> grid(m, vector<int>(n));
    int count = 0;
    cout<<pathCount(0,0,grid);
    return 0;
}