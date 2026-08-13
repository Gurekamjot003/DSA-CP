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

long long translation_cost(long long n){
    return n*(n+1ll)/2ll;
}

long long find_minimum_cost(int& cost, string& s){
    vector<int> freq(5);
    for(auto ch: s) freq[ch-'A']++;
    long long ans = 0;
    sort(freq.rbegin(), freq.rend());
    int total = s.size();
    for(int i = 0; i<freq.size(); i++){
        if((translation_cost(total) - translation_cost(total - freq[i])) > cost) 
            ans += 0ll + cost;
        else return ans + translation_cost(total);
        total -= freq[i];
    }
    return ans;
}

int main(){
    ifstream in("input.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        int c; in>>c; 
        string s;
        in>>s;

        cout<<find_minimum_cost(c, s)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}