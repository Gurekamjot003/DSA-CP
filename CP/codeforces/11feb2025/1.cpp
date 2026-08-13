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

bool isIncPos(int n1, int n2){
    int req = n1-n2;
    if(req == -1) req += 9;
    if(req<0) return false;
    return req%9 == 8;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1, n2;
        cin>>n1>>n2;
        isIncPos(n1, n2)? cout<<"YES": cout<<"NO";
        cout<<endl;
    }
    return 0;
}