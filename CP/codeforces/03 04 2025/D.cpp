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
#define v vector

const long long MOD = 998244353;
const int MAXN = 500000;

ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while(exp > 0) {
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

vector<ll> fact(MAXN + 1), invFact(MAXN + 1);

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN] = modExp(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if(r < 0 || r > n)
        return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int solve(vvi& dp, vi& c, int odd, int i = 0, int cur = 0){
    // if(cur == odd) return 1;
    if(cur>odd) return 0;
    if(i>=c.size()){
        if(cur == odd) return 1;
        return 0;
    }
    if(dp[i][cur] != -1) return dp[i][cur];
    int pick = 0;
    if(c[i]) pick = solve(dp, c, odd, i+1, cur + c[i]);
    int skip = solve(dp, c, odd, i+1, cur);
    return dp[i][cur] = (pick + skip)%MOD;
}

int even_string(vi & c){
    int odd_rem, even_rem;
    int sum = accumulate(c.begin(), c.end(), 0);
    v<v<int>> dp(26, v<int>(sum + 1, -1));
    odd_rem = even_rem = sum/2;
    
    if(sum%2) odd_rem++;
    
    ll number_of_solutions = solve(dp, c, odd_rem);
    
    number_of_solutions = ((number_of_solutions*fact[even_rem])%MOD * fact[odd_rem]) % MOD;
    for(int i = 0; i<26; i++){
        number_of_solutions = (number_of_solutions* invFact[c[i]])%MOD;
    }
    return number_of_solutions;
}

int main(){
    ifstream in("input string.txt");
    precomputeFactorials();
    
    int t; in>>t;
    while(t--){
        int n = 26;
        vi c(n);
        
        for(int i = 0; i<n; i++) in>>c[i];
        cout<<even_string(c)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}