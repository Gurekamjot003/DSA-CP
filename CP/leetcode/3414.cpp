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

class Solution {

    vi index;

    int get_sum(vi& picked, vvi& intervals){
        int sum = 0;
        for(auto& n: picked) sum += intervals[index[n]][2];
        return sum;
    }
    bool is_less(vi& ans, vi& cur, vvi& intervals){
        if(cur.size() == 0) return false;
        int sum = get_sum(ans, intervals) - get_sum(cur, intervals);
        if(sum != 0) return sum>0;

        // check for lexico
        sort(all(cur));
        return cur<ans;
    }

    int solve(vi& ans, vvi& dp, vvi& intervals, vi& cur, int i = 0){
        if(i == intervals.size() or cur.size() == 4){
            if(is_less(ans, cur, intervals)) ans = cur;
            return 0;
        }

        if(dp[i][cur.size()] != -1) return dp[i][cur.size()];
        cur.push_back(i);
        int pick = intervals[index[i]][2] + solve(ans, dp, intervals, cur, i+1);
        cur.pop_back();
        int skip = solve(ans, dp, intervals,cur, i+1);
        return dp[i][cur.size()] = max(pick, skip);
    }
    
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        index = vi(n);
        iota(all(index), 0);
        sort(all(index), [&](auto a, auto b){
            return intervals[a][0]<intervals[b][0] or (intervals[a][0] == intervals[b][0] && intervals[a][1]>intervals[b][1]);
        });

        vvi dp(n, vi(4,-1));
        vi ans, cur;
        solve(ans, dp, intervals, cur);
        return ans;
    }
};