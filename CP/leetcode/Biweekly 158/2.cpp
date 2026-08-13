#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vb vector<bool>
#define umapii unordered_map<int, int>
#define mapii map<int, int>
#define useti unordered_set<int>
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
// #define endl "\n"
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep1(i, n) for(int i = 1; i<=n; i++)
#define rev(i, n, step) for(int i = n-1; i>=0; i-= step)

template<typename T>
void amin(T& a, T b){ a = min(a, b); }
template<typename T>
void amax(T& a, T b){ a = max(a, b); }

template<typename T>
T gcd(T a, T b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

vector<int> prime_numbers_upto(int n){
    vector<bool> is_prime(n+1, true);
    vi ans;
    for(int i = 2; i<=n; i++){
        if(!is_prime[i]) continue;
        ans.push_back(i);
        for(int j = i*2; j<=n; j+=i) is_prime[j] = false;
    }
    return ans;
}

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

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}


// no stock - 3 options buy, sell & skip
// already bought state - sell or skip
// short selling state - buy or skip

const int NEGINF = -1e15;

ll solve(vi& prices, int k, vvvll& dp, int n, int i = 0, int state = 0, int transaction_count = 0){
    if(transaction_count == k) return 0;

    if(i>=n){
        if(state != 0) return NEGINF;
        return 0;
    }

    if(dp[i][transaction_count][state] != NEGINF) return dp[i][transaction_count][state];

    ll ans = NEGINF;
    if(state == 0){ // no stock state
        // buy
        amax(ans, -prices[i] + solve(prices, k, dp, n, i+1, 1, transaction_count));
        // short sell 
        amax(ans, prices[i] + solve(prices, k, dp, n, i+1, 2, transaction_count));
    }
    else if(state == 1){ // bought stock state
        // sell
        amax(ans, prices[i] + solve(prices, k, dp, n, i+1, 0, transaction_count+1));
    }
    else{ // short sold state
        // buy back
        amax(ans, -prices[i] + solve(prices, k, dp, n, i+1, 0, transaction_count+1));
    }
    // wait
    amax(ans, solve(prices, k, dp, n, i+1, state, transaction_count));
    
    return dp[i][transaction_count][state] = ans;
}

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vvvll dp(n, vvll(k, vll(3, NEGINF)));
        return solve(prices, k, dp, n);
    }
};