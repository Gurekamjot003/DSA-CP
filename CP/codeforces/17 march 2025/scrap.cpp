#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF (INT64_MAX / 10)

ll equalization(ll x, ll y) {
    int i = 60; 
    while (i > 0 && ((1LL << (i - 1)) & x) == 0) {
        i--;
    }
    int j = 60;
    while (j > 0 && ((1LL << (j - 1)) & y) == 0) {
        j--;
    }
    
    // Remove the common prefix bits
    while (i > 0 && j > 0 && 
           (((bool)((1LL << (i - 1)) & x)) == ((bool)((1LL << (j - 1)) & y)))) {
        i--; 
        j--;
    }
    
    // 'i' and 'j' now denote the count of mismatched bits.
    int X = i, Y = j;
    int maxIt = 60;  // Allowed operations from 0 to 59, with a base at it = 60.
    
    // Create a 3D DP table with dimensions (X+1) x (Y+1) x (maxIt+1)
    vector<vector<vector<ll>>> dp(X + 1, vector<vector<ll>>(Y + 1, vector<ll>(maxIt + 1, INF)));
    
    // Base case: when it == maxIt
    for (int a = 0; a <= X; a++) {
        for (int b = 0; b <= Y; b++) {
            dp[a][b][maxIt] = (a == 0 && b == 0) ? 0 : INF;
        }
    }
    
    // Fill the table in descending order of it (from 59 down to 0)
    for (int it = maxIt - 1; it >= 0; it--) {
        for (int a = 0; a <= X; a++) {
            for (int b = 0; b <= Y; b++) {
                ll cost = (1LL << it);  // cost of performing operation at step 'it'
                ll option1 = INF, option2 = INF;
                if (a - it >= 0)
                    option1 = dp[a - it][b][it + 1];
                if (b - it >= 0)
                    option2 = dp[a][b - it][it + 1];
                ll pick = cost + min(option1, option2);
                ll skip = dp[a][b][it + 1];
                dp[a][b][it] = min(pick, skip);
            }
        }
    }
    
    return dp[X][Y][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("input string.txt");
    int t;
    in >> t;
    while (t--) {
        ll x, y;
        in >> x >> y;
        cout << equalization(x, y) << "\n";
    }
    
    return 0;
}
