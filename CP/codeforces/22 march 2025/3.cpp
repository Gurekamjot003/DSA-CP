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

ll serval_and_the_formula(int x, int y){
    if(x == y) return -1;
    for(int i =60; i>=0; i--){
        if(((1ll<<i) & x) or ((1ll<<i)& y)){
            return (1ll<<(i+1)) - max(x, y);
        }
    }
    return -1;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int x, y;
        in>>x>>y;
        
        cout<<serval_and_the_formula(x, y)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}