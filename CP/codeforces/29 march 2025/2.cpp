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

bool lady_bug(string&a, string& b){
    int even_zeros = 0, odd_zeros = 0;
    for(int i = 0; i<b.size(); i++){
        if(b[i] == '0'){
            (i%2 == 0? even_zeros: odd_zeros) ++;
        }
    }
    for(int i = 0; i<a.size(); i++){
        if(a[i] == '1'){
            (i%2 == 0? odd_zeros: even_zeros)--;
        }
    }
    return (odd_zeros >=0 && even_zeros >=0);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        string a, b;
        in>>a>>b;

        cout<<(lady_bug(a, b)? "YES": "NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}