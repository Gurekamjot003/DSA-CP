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

bool unlock_the_safe(vi& a, vi& b, int k){
    int diff = 0;
    int max_diff_index = 0;
    int max_diff = INT_MIN;
    for(int i=  0; i<a.size(); i++){
        int cur = min(abs(a[i] - b[i]), 9-abs(a[i] - b[i]));
        if(cur>max_diff){
            max_diff = cur;
            max_diff_index = i;
        }
        diff += cur;
    }
    if(diff>k) return false;
    if((k-diff)%2 == 0) return true;
    diff -= max_diff;
    diff += (9-max_diff);
    if(k>=diff) return true;
    return false;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        vi a(n), b(n);
        for(int i = 0; i<n; i++) in>>a[i];
        for(int i = 0; i<n; i++) in>>b[i];
        cout<<(unlock_the_safe(a, b, k)? "YES": "NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}