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

vvi serval_and_final_mex(vi& a){
    int n = a.size();
    vvi ans;
    if(a.back() == 0){
        ans.push_back({n-1, n});
        a.pop_back();
        int val;
        if(a.back() == 1) val = 2;
        else val = 1;
        a.pop_back();
        a.push_back(val);
    }
    int first = -1, last = -1;
    for(int i = 0; i<a.size(); i++){
        if(a[i] == 0){
            if(first == -1) first = i;
            last = i;
        }
    }
    if(first == -1){
        ans.push_back({1, (int)a.size()});
        return ans;
    }
    ans.push_back({1, (int)a.size() -1});
    ans.push_back({1, 2});
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        vvi ans = serval_and_final_mex(a);
        cout<<ans.size()<<endl;
        for(auto& n: ans){
            for(auto& m: n) cout<<m<< " ";
            cout<<endl;
        }
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}