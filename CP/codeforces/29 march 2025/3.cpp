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

ll asuna_and_the_mosquitoes(vi& a){
    ll ans = 0;
    int odd_count = 0;
    for(ll n: a){
        ans += n;
        if(n%2){
            odd_count++;
        }
    }
    if(odd_count == 0 or odd_count == a.size()) return *max_element(a.begin(), a.end());
    return ans - odd_count + 1;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        cout<<asuna_and_the_mosquitoes(a)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}