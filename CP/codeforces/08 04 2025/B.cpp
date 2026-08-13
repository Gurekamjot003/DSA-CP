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

int expensive_number(string& n){
    int sz = n.size();
    int i = sz-1;
    int ans = 0;
    while(i>=0 && n[i] =='0'){
        ans ++;
        i--;
    }
    i--;
    while(i>=0){
        if(n[i] != '0'){
            ans++;
        }
        i--;
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        string n; in>>n;
        
        cout<<expensive_number(n)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}