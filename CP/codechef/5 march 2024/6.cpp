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



vi mex_p(vvi & graph, vi& values){

}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi values(n);
        for(int i = 0; i<n; i++) in>>values[i];
        vvi graph(n);
        for(int i = 0; i<n-1; i++){
            int u, v;
            in>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vi ans = mex_p(graph, values);
        for(auto n: ans) cout<<n<<" ";
        cout<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}