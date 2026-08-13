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

vi disappearing_permutations(vi& p, vi& d){
    int n = p.size();
    vi index(n+1);
    for(int i = 0; i<n; i++) index[p[i]] = i;
    vb changed(n);
    int cur = 0;
    vi ans(n);
    for(int i = 0; i<n; i++){
        int cur_index = d[i];
        
        while(!changed[index[cur_index]]){
            changed[index[cur_index]] = true;
            cur_index = index[cur_index] + 1;
            cur++;
        }
        ans[i] = cur;
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi p(n), d(n);
        for(int i= 0; i<n; i++) in>>p[i];
        for(int i= 0; i<n; i++) in>>d[i];
        vi ans = disappearing_permutations(p, d);
        for(auto& n: ans) cout<<n<< " ";
        cout<<endl;
        // cout<<program_name(parameters)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}