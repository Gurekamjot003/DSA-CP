#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define vb vector<bool>
#define umapii unordered_map<int, int>
#define mapii map<int, int>
#define useti unordered_set<int>

int n, m;
const int mod = 998244353;

int solve(vvb& grid, int d, vector<vector<vector<int>>>& dp, int row, int col, int cur_count, vector<vector<vector<ll>>>& pref_dp) {
    if(cur_count > 1) return 0;
    if(grid[row][col] == 0) return 0;
    if(dp[row][col][cur_count] != -1) return dp[row][col][cur_count];
    // If we are at the top row with one same-row move already done, we count this as one valid path.
    if(cur_count == 1 && row == 0) return dp[row][col][cur_count] = 1;
    
    int ans = 0;
    
    // Only allow same row moves if no same-row move has been done in this chain.
    if(cur_count == 0) {
        int left = max(0, col - d);
        int right = min(m - 1, col + d);
        for(int i = left; i <= right; i++) {    // check for same row
            if(i == col) continue;
            ans = (ans + solve(grid, d, dp, row, i, cur_count + 1, pref_dp)) % mod;
        }
    }
    
    // If we are on the top row and not taking upward moves, add one path.
    if(row == 0) {
        ans = (ans + 1) % mod;
    } else {
        int left = max(0, col - d);
        int right = min(m - 1, col + d);
        for(int j = left; j <= right; j++) {
            // Check if the horizontal move is within allowed Euclidean distance
            if(1 + (col - j) * (col - j) > d * d) continue;
            ans = (ans + solve(grid, d, dp, row - 1, j, 0, pref_dp)) % mod;
        }
    }
    
    return dp[row][col][cur_count] = ans;
}

int igor_and_mountain(vvb& grid, int d) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
    vector<vector<vector<ll>>> pref_dp(n, vector<vector<ll>>(m, vector<ll>(2, -1)));
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        ans  = (ans + solve(grid, d, dp, n - 1, i, 0, pref_dp)) % mod;
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; 
    in >> t;
    while(t--){
        int d; 
        in >> n >> m >> d;
        vvb grid(n, vb(m, false));
        for(int i = 0; i < n; i++){
            string cur;
            in >> cur;
            for(int j = 0; j < m; j++){
                if(cur[j] == 'X') grid[i][j] = true;
            }
        }
        cout << igor_and_mountain(grid, d) << endl;
    }
    return 0;
}
