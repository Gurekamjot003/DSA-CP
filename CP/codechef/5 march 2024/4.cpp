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

vll find_beautiful_sequence(long long& n, long long& m){
    vll ans;
    ans.push_back(n);
    int position = 0;
    for(int i = 0; (((1ll<<i) | n) <= m) && i<64; i++){
        if(((1ll<<i) & n) == 0)
            ans.push_back((1ll<<i) | n);
    }
    // cout<<position<<" ";
    return ans;

}

int main(){
    ifstream in("input.txt");
    int t; in>>t;
    while(t--){
        long long n, m; in>>n>>m;
        vll ans = find_beautiful_sequence(n, m);
        if(ans.size() > 1){
            cout<<ans.size()<<endl;
            for(auto n: ans) cout<<n<<" ";
        }
        else cout<<(-1);
        cout<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}