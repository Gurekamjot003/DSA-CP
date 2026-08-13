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

vi Vicious_Labyrinth(int n, int k){
    vi ans(n);
    if(k%2 == 0){
        for(int i = 0; i<n; i++){
            ans[i] = n-1;
        }
        ans[n-2] = n;
    }
    else{
        for(int i = 0 ; i<n; i++){
            ans[i] = n;
        }
        ans[n-1] = n-1;
    }
    return ans;
}

int main(){
    // ifstream in("input string.txt");
    // int t; in>>t;
    // while(t--){
    //     int n, k;
    //     in>>n>>k;
    //     vi ans = Vicious_Labyrinth(n, k);
    //     for(auto& n: ans) cout<<n<<" ";
    //     cout<<endl;
    //     // cout<<program_name(parameters)<<endl;
    // }
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vi ans = Vicious_Labyrinth(n, k);
        for(auto& n: ans) cout<<n<<" ";
        cout<<endl;
        // cout<<program_name(parameters)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}