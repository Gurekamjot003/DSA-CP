#ifndef GUREKAM
#define GUREKAM
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

#define vvvll vector<vvll>
#define vvll vector<vll>

class Solution {

    ll solve(vvvll& dp, vi& requests, int left, int right, bool is_left){
        if(left == 0 && right == requests.size()){
            return 0;
        }

        if(dp[left][right][is_left] != -1) return dp[left][right][is_left];

        ll ans = INT64_MAX;
        ll count = left + requests.size()-right;
        if(left > 0){
            if(is_left) amin(ans, count*(requests[left+1]-requests[left]) + solve(dp, requests, left-1, right, true));
            else amin(ans, count*(requests[right-1]-requests[left]) + solve(dp, requests, left-1, right, true));
        }
        if(right<requests.size()){
            if(is_left) amin(ans, count*(requests[right] - requests[left+1]) + solve(dp, requests, left, right+1, false));
            else amin(ans, count*(requests[right] - requests[right-1]) + solve(dp, requests, left, right+1, false));
        }
        return dp[left][right][is_left] = ans;
    }

    int bs(vi& requests, int target){
        rep(i, requests.size()) if(requests[i] == target) return i;
        return -1;
    }
    
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        if(requests.size() == 1 && requests[0] == start) return 0;
        bool found = false;
        requests.insert(requests.begin(), -1);
        rep(i, requests.size()){
            if(requests[i] == start) found = true;
        }
        if(!found) requests.push_back(start);
        int r = requests.size();
        sort(all(requests));
        int i = bs(requests, start);
        vvvll dp(r+2, vvll(r+2, vll(2,-1)));
        return solve(dp, requests, i-1, i+1, true);
    }
};