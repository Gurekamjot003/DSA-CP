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

bool possibleThree(vi& a, vi& b){
    useti st;
    useti st2;
    for(auto n: a){
        st.insert(n);
    }
    for(auto n: b){
        st2.insert(n);
    }
    
    return (st.size()+st2.size())>=4;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        vi b(n);
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
        cout<<(possibleThree(a, b) ? "YES": "NO")<<endl;
    }
    return 0;
}