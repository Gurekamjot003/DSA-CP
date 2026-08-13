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
#define v vector
#define INF 1e18;

// ll solve(v<v<v<ll>>> & dp, int x, int y){
    
//     for(int it = 0; it<60; it++){
//         dp[0][0][it] = 0;
//     }
//     for(int i = 0; i<x; i++){
//         for(int j = 0; j<y; j++){
//             dp[i][j][60] = INF;
//         }
//     }

//     int i = 0,j = 0;
//     for(int it = 59; it>=0; it--){
//         ll pick = 0;
//         if((i+it) <=x) pick = min(pick, dp[i+it][j][it-1]);
//         if((j+it) <= y) pick = min(pick, dp[i][j+it][it-1]);
//         pick += (1ll<<it);
//         ll skip = dp[i][j][it-1];
//         dp[i][j][it] = min(pick, skip);
//     }
//     return dp[x][y][0];
// }
v<v<v<ll>>> dp(60, v<v<ll>>(60, v<ll>(60, -1)));
ll solve( int x, int y, int it = 0){
    if(x == 0 && y==0) return 0;
    if(it>x && it>y) return INF;
    if(x<0 or y<0) return INF;
    if(it>=60) return INF;
    if(dp[x][y][it] != -1 && dp[x][y][it] <= 1e17) return dp[x][y][it];
    ll pick = (1ll<<it) + min(solve(x-it, y, it+1), solve(x, y-it, it+1));
    ll skip = solve( x, y, it+1);
    ll ans = min(pick, skip);
    return dp[x][y][it] = min(pick, skip);
}

ll equalization(ll x, ll y){
    int i = 60; 
    while(i>0 && (1ll<<(i-1) & x) == 0){
        i--;
    }
    int j = 60;
    while(j>0 && (1ll<<(j-1) & y) == 0){
        j--;
    }
    // i++; j++;
    
    while(i>0 && j>0 && ((bool(1ll<<(i-1) & x) ) == (bool(1ll<<(j-1) & y)))){
        i--; j--;
    }
    
    // cout<<i<<" "<<j<<endl;
    return solve(i, j);
    return 0;
}

int main(){
    ifstream in("input string.txt");
    for(int i = 0; i<60; i++){
        for(int j = 0; j<60; j++){
            solve(i,j);
        }
    }

    int t; in>>t;
    while(t--){
        ll x, y; 
        in>>x>>y;
        
        cout<<equalization(x, y)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}