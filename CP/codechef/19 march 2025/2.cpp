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

pii big_difference(int n, int k){
    int x = 2;
    int y = n;
    if(y%2 == 0) y--;
    if((y-x) < k) return {-1, -1};
    return {x, y};
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n,k; 
        in>>n>>k;
        auto ans = big_difference(n, k);
        cout<<ans.first<<" "<<ans.second;
        cout<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}