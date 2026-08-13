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

int array_operations(vi& a){
    int odd_max = 0, even_max = 0;
    for(int i = 0; i<a.size(); i+=2) odd_max = max(a[i], odd_max);
    for(int i = 1; i<a.size(); i+=2) even_max = max(a[i], even_max);
    return max(odd_max + (int)a.size()/2, even_max + (int)a.size()/2 - 1);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        cout<<array_operations(a)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}