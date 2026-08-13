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

ll large_array_and_segments(vi& a, int k, ll x){
    ll ans = 0, n = a.size();
    // ll right = 0, max_right = n*k;
    ll single_sum = accumulate(a.begin(), a.end(), 0ll);
    ll total_sum = single_sum*k;
    if(total_sum < x) return 0;
    ans += ((total_sum-x)/single_sum)*n;
    
    x%=single_sum;
    if(x == 0) x = single_sum;
  
    int left = 0;
    while(single_sum >= x && left<a.size()){
        single_sum -= a[left++];
        ans++;
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k;
        ll x; 
        in>>n>>k>>x;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        cout<<large_array_and_segments(a, k, x)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}