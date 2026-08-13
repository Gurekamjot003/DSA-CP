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

int find(vi& arr, int target){
    int left = 0, right = arr.size();
    int ans = right;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid] >= target){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return ans;
}

ll two_colors(vi& arr, int n){
    for(int i = 0; i<arr.size(); i++) if(arr[i] == n) arr[i] = n-1;
    sort(arr.begin(), arr.end());
    vll pref_sum = {0};
    for(int i = 0; i<arr.size(); i++) pref_sum.push_back(pref_sum.back() + arr[i]);
    ll ans = 0;
    for(int i = 0; i<arr.size(); i++){
        int ind = find(arr, n - arr[i]);
        ll cur = pref_sum.back() - pref_sum[max(ind, i+1)];
        int nums = arr.size()-(max(ind, i+1));
        cur -= ((n-arr[i]-1) * 1ll * nums);
        ans += cur*2ll;
    }
    return ans;
}

int main(){
    // ifstream in("input string.txt");
    // int t; in>>t;
    // while(t--){
    //     int n, m; 
    //     in>>n>>m;
    //     vi a(m);
    //     for(int i = 0; i<m; i++) in>>a[i];
    //     cout<<two_colors(a, n)<<endl;
    // }
    int t; cin>>t;
    while(t--){
        int n, m; 
        cin>>n>>m;
        vi a(m);
        for(int i = 0; i<m; i++) cin>>a[i];
        cout<<two_colors(a, n)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}