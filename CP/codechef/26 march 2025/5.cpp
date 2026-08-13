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

int set_major_prefix(vi& arr){
    int n = arr.size();
    vi freq_till_len(n+1);
    arr.insert(arr.begin(), 0);
    for(int i = 1; i<=n; i++){
        freq_till_len[i] = freq_till_len[i-1] + (arr[i] == arr[1]);
    }

    ll max_suffix = 2*freq_till_len[1] - 1;
    ll ans = 1;
    for(int i = 2; i<=n; i++){
        if(2*freq_till_len[i] <=i) break;
        if(arr[i] == arr[1] && (2*freq_till_len[i] - i) > max_suffix) ans++;
        max_suffix = max(max_suffix, 2ll*freq_till_len[i]-i);
    }
    return ans;

}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        // set_major_prefix(a);
        cout<<set_major_prefix(a)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}