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

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

bool simple_repetition(int n, int k){
    if(n == 1 && k == 2) return true;
    if(k>1) return false;
    return is_prime(n);
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int x, k; 
        in>>x>>k;
        
        cout<<(simple_repetition(x, k)? "yes": "no")<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}