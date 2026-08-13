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

ll array_recoloring(vi& arr, int k){
    if(k == 1){
        ll ans = 0;
        if(arr.size() > 2){
            for(int i = 1; i<arr.size()-1; i++){
                ans = max(ans, (ll)arr[i]);
            }
            ans += max(arr[0], arr.back());
        }
        ans = max(ans, 0ll + arr[0] + arr.back());
        return ans;
        
    }
    sort(arr.rbegin(), arr.rend());
    ll ans = 0;
    for(int i = 0; i<=k; i++){
        ans += 0ll + arr[i];
    }

    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        vi a(n);
        for(int i =0; i<n; i++) in>>a[i];
        
        cout<<array_recoloring(a, k)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}