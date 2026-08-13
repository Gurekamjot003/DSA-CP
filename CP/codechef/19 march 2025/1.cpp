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

int placing_01_10(int x, int y){
    if(x>y) swap(x, y);
    int diff = y-x;
    if(diff <=1) return x+y;
    return 2*x+1 + 2*(diff-1);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int x, y;
        in>>x>>y;

        
        cout<<placing_01_10(x,y)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}