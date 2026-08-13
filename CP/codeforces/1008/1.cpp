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

bool Final_verdict(vi& arr, int target){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    float avg = sum/(arr.size() + 0.0000);
    return target == avg;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, target; 
        in>>n>>target;
        vi arr(n);
        for(int i = 0; i<n; i++) in>>arr[i];
        cout<<(Final_verdict(arr, target)? "YES": "NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}