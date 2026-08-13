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

vvi flip_or_reverse(string& a, string& b){
    vvi ans;
    int prev = -1;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]){
            prev = i;
            break;
        }
    }
    if(prev == -1) return ans;
    for(int i = prev; i<=a.size(); i++){
        if(i == (a.size()) or a[i] == b[i]){
            if(prev < i){
                ans.push_back({1, prev, i-1});
            }
            prev = i+1;
        }
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        string a, b;
        in>>a>>b;
        vvi ans = flip_or_reverse(a, b);
        cout<<ans.size()<<endl;
        for(int i = 0; i<ans.size(); i++){
            for(int j = 0; j<ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}