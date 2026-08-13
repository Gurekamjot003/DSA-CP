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

ll can_you_reach(vi& h){
    ll ans = 0;
    int left = 0, local_min_max = -1;
    vector<int> local;
    for(int i = 1; i<(h.size()-1); i++){
        if(h[i-1] == h[i+1]){
            local.push_back(i);
        }
    }
    if(local.size() <= 1){
        ll n = h.size();
        return n*(n-1)/2;
    }
    for(int i = 1; i<(local.size()-1); i++){
        ll n = local[i+1] - local[i-1] +1;
        ans += n*(n-1)/2;
    }
    for(int i = 0; i<(local.size()-1); i++){
        ll n = local[i+1] - local[i] +1;
        ans -= (n*(n-1))/2;
    }
    ll n = local[1] +1;
    ans += (n*(n-1))/2;
    n = h.size() - local[local.size()-2];
    ans += n*(n-1)/2;
    return ans;
    
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi h(n);
        for(int i = 0; i<n; i++) in>>h[i];
        cout<<can_you_reach(h)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}