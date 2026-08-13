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

vector<string> huh_easy(int n, int k){
    if( k< (n/2)) return {"-1"};
    string a, b;
    bool flag = false;
    for(int i = 0; i<n; i++){
        a.push_back('A' + flag);
        flag = !flag;
    }
    flag = false;
    for(int i = 0; i<n; i++){
        b.push_back('C' - flag);
        flag = !flag;
    }
    int cur = n/2; 
    for(int i = 0; i<n; i+=2){
        if(cur == k) break;
        b[i] = 'A';
        cur++;
    }
    return {a, b};
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        vector<string> ans = huh_easy(n, k);
        for(auto n: ans) cout<<n<<endl;
      
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}