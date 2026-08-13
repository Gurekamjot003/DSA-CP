#include<bits/stdc++.h>
using namespace std;

bool solve(int cur, int target, int i, int n, vector<vector<int>>& dp){
    if(cur == target) return true;
    if(cur>target or i == n) return false;
    if(dp[cur][i] != -1) return dp[cur][i];
    bool result = solve(cur+12, target, i+1, n, dp) || solve(cur+11, target, i+1, n, dp) || solve(cur+10, target, i+1, n, dp);
    return dp[cur][i] = result;

}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int k; cin>>k;
        if(solve(0, k, n)) cout<<"yes";
        else cout<<"no";
        cout<<endl;
        
    }
    return 0;
}