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

int To_zero(int n, int k){
    if(n<=0) return 0;
    if(n%2){
        return 1 + To_zero(n-k, k);
    }
    return ceil((n + 0.0)/(k-1));
}

int main(){
    ifstream in("input string.txt");
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        cout<<To_zero(n, k)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}