#ifndef GUREKAM
#define GUREKAM
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
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

bool possible(vvpii& graph, int n, ll k, int min_wt){
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});
    vb visited(n);
    while(!pq.empty()){
        auto[w, u] = pq.top();
        pq.pop();
        if(u == n-1){
            return true;
        }
        if(visited[u]) continue;
        visited[u] = true;
        for(auto& [v, new_w]: graph[u]){
            if((w+new_w)>k or new_w<min_wt or visited[v]) continue;
            pq.push({w+new_w, v});
        }
    }
    return false;
}

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vvpii graph(n+1);

        int max_cost = INT_MIN, min_cost = INT_MAX;
        for(auto& e: edges){
            if(!online[e[0]] or !online[e[1]]) continue;
            graph[e[0]].push_back({e[1], e[2]});
            amax(max_cost, e[2]);
            amin(min_cost, e[2]);
        }
        int left = min_cost, right = max_cost;
        int ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(possible(graph, n, k, mid)){
                ans = mid;
                left = mid+1;
            }
            else right=mid-1;
            

        }
        return ans;
        
    }
};