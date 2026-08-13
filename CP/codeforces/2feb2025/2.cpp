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



int findMinCost(vi& a, int k){
    sort(a.begin(), a.end());
    int left = 1, right = 1+a.size()-k;
    int index = 1;
    for(; right<a.size(); right+=2, index++){
        while(a[left] == index)
    }
    return index;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; int k;
        cin>>n>>k;
        vi a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        cout<<findMinCost(a, k)<<endl;
    }
    return 0;
}