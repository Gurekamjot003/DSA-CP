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

vi combination_lock(int n){
    vi ans;
    if(n%2 == 0){
        ans.push_back(-1);
        return ans;
    }
    for(int i = 1; i<=n; i+=2) ans.push_back(i);
    for(int i = 2; i<n; i+=2) ans.push_back(i);
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        
        vi ans = combination_lock(n);
        for(auto & n: ans) cout<<n<< " ";
        cout<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}