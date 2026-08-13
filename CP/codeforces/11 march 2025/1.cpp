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

bool is_a_square(int l, int r, int d, int u){
    
    if(r+l != d+u) return false;
    double side_len = sqrt(l*l+u*u);
    if(sqrt(u*u + r*r) != side_len or sqrt(r*r + d*d) != side_len or sqrt(d*d + l*l)!= side_len or side_len == 0) return false;
    return true;
}

int main(){
    // ifstream in("input string.txt");
    // int t; in>>t;
    // while(t--){
    //     int l, r ,d, u;
    //     in>>l>>r>>d>>u;
        
        
    //     cout<<(is_a_square(l,r,d, u)? "YES":"NO")<<endl;
    // }
   
    int t; cin>>t;
    while(t--){
        int l, r ,d, u;
        cin>>l>>r>>d>>u;
        
        
        cout<<(is_a_square(l,r,d, u)? "YES":"NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}