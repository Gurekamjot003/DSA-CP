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

bool is_possible(vi& arr, int max_value, int k){
    
    vector<bool> present(max_value);
    int total = 0;
    int num_segments = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] < max_value){
            if(present[arr[i]]) continue;
            present[arr[i]] = true;
            total++;
        }
        if(total == max_value){
            num_segments++;
            total = 0;
            for(int i = 0; i<max_value; i++) present[i] = false;
        }
    }
    return num_segments>=k;
}

int min_max_mex(vi& arr, int k){
    int left = 0, right = *max_element(arr.begin(), arr.end())+1;
    int ans = left;
    while(left<=right){
        int mid = (left+right)/2;
        if(is_possible(arr, mid, k)){
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        
        cout<<min_max_mex(a, k)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}