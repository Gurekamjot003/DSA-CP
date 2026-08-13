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
#define rev(i, n, step) for(int i = n-1; i>=0; i-= step)
#define vd vector<pair<char, double>>
#define vvd vector<vd>


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

    bool dfs(map<string, vector<pair<string, double>>>& graph, string u, string end, double& ans, set<string>& visited){
        if(u == end){
            return true;
        }
        if(visited.count(u)) return false;
        visited.insert(u);
        for(auto & [v, cur_val]: graph[u]){
            ans*=cur_val;
            if(dfs(graph, v, end, ans, visited)) return true;
            ans/=cur_val;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i<equations.size(); i++){
            auto& eq = equations[i];
            graph[eq[0]].push_back({eq[1], values[i]});
            graph[eq[1]].push_back({eq[0], 1.0/values[i]});
        }

        vector<double> ans;
        for(auto& query: queries){
            string c1 = query[0];
            string c2 = query[1];
            if(graph.find(c1) == graph.end()){
                ans.push_back(-1);
                continue;
            }
            set<string> visited;
            double cur = 1.0;
            if(!dfs(graph, c1, c2, cur, visited)) cur = -1;
            ans.push_back(cur);
        }
        return ans;


    }
};