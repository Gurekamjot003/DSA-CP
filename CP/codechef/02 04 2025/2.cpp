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

int mod = 998244353;

int power (int exp, int base = 2){
    ll ans = 1;
    while(exp>0){
        if(exp%2 == 1){
            ans = (ans * base)%mod;
        }
        base = (base * base)%mod;
        exp/=2;
    }
    return ans;
}

int shall_we_play_a_game(int n){
    
    if(n%2 == 0){
        return (power(n-1) + power(n-2))%mod;
    }
    return power(n-1);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        
        cout<<shall_we_play_a_game(n)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}