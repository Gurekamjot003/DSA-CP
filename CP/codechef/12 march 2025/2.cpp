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

int find_pivot(vi& x, vi& y){
    int pivot = y[0];
    v<pii> v(x.size());
    for(int i = 0; i<v.size(); i++){
        v[i] = {abs(pivot - x[i]), x[i]};
    }
    sort(v.begin(), v.end());
    for(int i = 0; i<v.size(); i++){
        if(v[i].second != y[i]) return -1;
    }
    for(int i = 0; i<x.size(); i++){
        if(x[i] == pivot) return i+1;
    }
    return -1;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi x(n);
        for(int i = 0; i<n; i++) in>>x[i];
        vi y(n);
        for(int i = 0; i<n; i++) in>>y[i];

        cout<<find_pivot(x, y)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}