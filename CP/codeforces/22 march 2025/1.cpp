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

bool serval_and_string_theory(int k , string& s){
    if(k == 0){
        for(int i = 0; i<s.size(); i++){
            if(s[i] == s[s.size()-1-i]) continue;
            if(s[i] > s[s.size()-1-i]) return false;
            return true;
        }
        return false;
    }
    unordered_set<char> letters;
    for(int i = 0; i<s.size(); i++){
        letters.insert(s[i]);
    }

    return letters.size()>=2;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, k; 
        in>>n>>k;
        string s;
        in>>s;
        cout<<(serval_and_string_theory(k, s)? "YES": "NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}