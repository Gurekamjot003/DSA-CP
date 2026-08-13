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

vll random_teams(int n, int m){
    ll kmax = (n-(m-1ll));
    kmax = kmax*(kmax-1ll)/2;
    ll higher_num_count = n%m;

    ll min = 0;
    ll num = n/m;
    min += higher_num_count * (num*(num+1))/2;
    ll lower_num_count = m - higher_num_count;
    min += lower_num_count*(num*(num-1))/2;
  
    return {min, kmax};
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, m; 
        in>>n>>m;
        vll ans = random_teams(n, m);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}