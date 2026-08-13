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

int team_training(vi& arr, int x){
    sort(arr.rbegin(), arr.rend());
    int left = 0;
    ll prod = 1;
    int ans = 0;
    for(int right = 0; right<arr.size(); right++){
        prod = arr[right];
        if((prod * (right - left+1))>=x){
            ans++;
            prod = 1;
            left = right +1;
        }
    }
    
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, x; 
        in>>n>>x;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        cout<<team_training(a, x)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}