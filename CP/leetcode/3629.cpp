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

vector<bool> prime_numbers_boolean(int n){
    vector<bool> is_prime(n+1, true);
    for(int i = 2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j = i*2; j<=n; j+=i) is_prime[j] = false;
    }
    return is_prime;
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
public:
    int minJumps(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_map<int, vector<int>> positions;
        int n = nums.size();
        rep(i, n){
            positions[nums[i]].push_back(i);
        }
        int max_ele = *max_element(all(nums));

        vb visited(n);
        queue<int> q;
        unordered_set<int> visited_primes;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front(); q.pop();

                if(u == n-1) return ans;

                if(!visited_primes.count(nums[u]) && is_prime(nums[u])){ // is_prime
                    for(int i = 1; (1ll*i*nums[u]) <= max_ele; i++){
                        for(auto& v: positions[i*nums[u]])
                        if(!visited[v]){
                            q.push(v);
                            visited[v] = true;
                        }
                        positions.erase(i*nums[u]);
                    }
                    visited_primes.insert(nums[u]);
                }
                if(u > 0 && !visited[u-1]){
                    q.push(u-1);
                    visited[u-1] = true;
                }
                if(u < (n-1) && !visited[u+1]){
                    q.push(u+1);
                    visited[u+1] = true;
                }
                
            }
            ans++;
        }
        return -1;
    }
};

