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

bool palindrome_possible(string& a, string& b){
    int zero_same = 0, one_same = 0, diff = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] == b[i]){
            a[i] == '0'? zero_same++: one_same++;
        }
        else diff++;
    }
    zero_same%=2;
    one_same%=2;
    diff%=2;
    if(zero_same + one_same + diff > 1) return false;
    return true;
}

int main(){
    ifstream in("input.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        string a, b;
        in>>a>>b;
        
        cout<<(palindrome_possible(a, b)? "YES":"NO")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}