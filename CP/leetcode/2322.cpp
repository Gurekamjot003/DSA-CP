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
    vi in_time, out_time, xor_sum;
    int timer = 0;
    vvi graph;
    void fill_xors(vi& nums, int u = 0, int parent = -1){
        in_time[u] = timer++;
        int cur_xor = 0;
        for(auto& v: graph[u]){
            if(v == parent) continue;
            fill_xors(nums, v, u);
            cur_xor^=xor_sum[v];
        }
        
        cur_xor ^= nums[u];
        xor_sum[u] = cur_xor;
        out_time[u] = timer++;
    }

    bool is_ancestor(int i, int j){
        return (in_time[i] <= in_time[j] && out_time[i] >= out_time[j]);
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.resize(n);
        xor_sum.resize(n);
        in_time.resize(n);
        out_time.resize(n);

        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        fill_xors(nums);
        
        int ans = INT_MAX;

        rep1(i, n-1){
            for(int j = i+1; j<n; j++){
                int val1, val2, val3;
                if(is_ancestor(i, j)){
                    val1 = xor_sum[j];
                    val2 = xor_sum[i]^val1;
                    val3 = xor_sum[0]^val1^val2;
                }
                else if(is_ancestor(j, i)){
                    val1 = xor_sum[i];
                    val2 = xor_sum[j]^val1;
                    val3 = xor_sum[0]^val1^val2;
                }
                else{
                    val1 = xor_sum[i];
                    val2 = xor_sum[j];
                    val3 = xor_sum[0]^val1^val2;
                }
                int max_val = max(val1, max(val2, val3));
                int min_val = min(val1, min(val2, val3));
                
                amin(ans, max_val - min_val);
            }
        }
        return ans;

    }
};