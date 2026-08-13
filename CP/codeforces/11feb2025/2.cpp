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

bool isConversionPossible(vi& arr){
    vi freq(*max_element(arr.begin(), arr.end()) + 1);
    for(auto n: arr) freq[n]++;
    int prev = 0;
    for(int i = 0; i<freq.size(); i++){
        freq[i]+=prev;
        if(freq[i] == 0) continue;
        if(freq[i]==1) return false;
        if(freq[i] >=2) freq[i]-=2;
        prev = freq[i];
    }
    return prev%2==0;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        isConversionPossible(arr)? cout<<"YES": cout<<"NO";
        cout<<endl;
    }
    return 0;
}