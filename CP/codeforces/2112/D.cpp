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

void dfs(int u, vvi& graph, vb& visited, vvi& ans, bool to_push = true){
    if(visited[u]) return;
    visited[u] = true;
    for(auto& v: graph[u]){
        if(to_push) ans.push_back({u, v});
        dfs(v, graph, visited, ans, !to_push);
    }
}

pair<bool, vvi> solve(vvi& graph, int n, vi& indegree){
    
    int node_with_indegree2 = -1;
    rep1(i, n){
        if(indegree[i] == 2) node_with_indegree2 = i;
    }
    if(node_with_indegree2 == -1) return {false, {}};

    vb visited(n+1);
    vvi ans;
    int node1 = graph[node_with_indegree2][0], node2 = graph[node_with_indegree2][1];
    ans.push_back({ node_with_indegree2, node2});
    visited[node2] = visited[node_with_indegree2] = true;

    dfs(node1, graph, visited, ans);
    for(auto& v: graph[node2]) dfs(v, graph, visited, ans);
    
    return {true, ans};

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vvi graph(n+1);
        vi indegree(n+1);
        rep(i, n-1){
            int u, v;
            in>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        auto [pos, ans] = solve(graph, n, indegree); 
        yn(pos);
        if(pos){
            rep(i, ans.size()){
                cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
            }
        }     
        // cout << result << endl;
    }
    return 0;
}