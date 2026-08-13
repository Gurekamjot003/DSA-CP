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

int bs(vi& arr, int target){
    int left = 0, right= arr.size() -1;
    while(left<= right){
        int mid = (left+right)/2;
        if(arr[mid] == target) return mid;
        if(arr[mid] > target){
            right = mid-1;
        }
        else left = mid+1;
    }
    return -1;
}

int solve(vi& arr, vvi & freq, vi & dp, int ind = 0){
    if(ind >= arr.size()) return 0;
    if(ind != 0 && arr[ind] == arr[ind-1]) return dp[ind] = solve(arr, freq, dp, ind + 1);
    if(arr[ind] == arr.back()) return arr[ind] = 1;
    if(dp[ind] != -1) return dp[ind];
    int i = bs(freq[arr[ind]], ind);
    int ans = INT_MAX/2;
    i++;
    for(; i<freq[arr[ind]].size(); i++){
        ans = min(ans,1 + solve(arr, freq, dp, freq[arr[ind]][i] + 1));
    }
    ans = min(ans,1 + solve(arr, freq, dp, ind + 1));
    return dp[ind] = ans;
}

int minimum_colors(vi& arr){
    vvi freq(*max_element(arr.begin(), arr.end()) + 1);
    for(int i = 0; i<arr.size(); i++) freq[arr[i]].push_back(i);
    vi dp(arr.size(), -1);
    return solve(arr, freq, dp);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>> a[i];
        cout<<minimum_colors(a)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}