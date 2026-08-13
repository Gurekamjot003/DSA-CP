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
#define NEG_INF INT64_MIN/2


ll serval_and_keitenzushi_buffet(vi& d, int k){
    int n = d.size();
    priority_queue<int> pq;
    ll ans = 0;
    for(int i = 0; i<d.size(); i++){
        pq.push(d[i]);
        if( (n-i) % (k+1) == 0){
            ans += pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        vi d(n);
        for(int i = 0; i<n; i++) in>>d[i];
        cout<<serval_and_keitenzushi_buffet(d, k)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}