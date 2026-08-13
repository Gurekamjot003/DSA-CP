#ifndef GUREKAM
#define GUREKAM
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvd vector<vector<double>>
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
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
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
#endif

void backtrack_and_solve(int n, int k, int m, vector<int>& time, vector<double>& mul, vvd& dp, int bit_mask, double cur_time, double& ans, int stage, int btk_size, int cur_size = 0, double max_time = 0){
    if(cur_size == btk_size){
        // if all reach other side no one has to return 
        double new_time  = max_time * mul[stage];
        int new_stage = (int)new_time%m;
        if(bit_mask == 0){
            solve(n, k, m, time, mul, dp, bit_mask, cur_time + new_time, ans, stage + new_stage);
            return;
        }

        //otherwise one of the individual has to return
        rep(i, n){
            //if on other side
            
            if((bit_mask ^ (1<<i)) & (1<<i)){

            }
        }
        return;
    }
    rep(i, n){
        //if at base camp
        if(bit_mask & 1<<i){
            backtrack_and_solve(n,k, m, time, mul, dp, bit_mask ^= 1<<i, cur_time, ans, btk_size, cur_size+1, max(max_time, 0.0 + time[i]));
        }
    }
}

void solve(int n, int k, int m, vector<int>& time, vector<double>& mul, vvd& dp, int bit_mask, double cur_time, double& ans, int stage){
    if(cur_time>ans or cur_time >= dp[bit_mask][stage]) return;
    if(bit_mask == 0){
        amin(ans, cur_time);
        return;
    }
    rep1(i, m){
        //backtrack and solve function
    }
}

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        vvd dp(1<<n, vector<double>(m, INT_MAX));
        int bit_mask = (1<<n) -1;
        int time = 0;

    }
};