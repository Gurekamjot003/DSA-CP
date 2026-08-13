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

void dfs(vi& branches, vvi& graph, vb& visited, int u, int cur_size = 0){
    bool found_next = false;
    for(auto& v: graph[u]){
        if(!visited[v]){
            visited[v] = true;
            found_next = true;
            dfs(branches, graph, visited, v, cur_size+1);
        }
    }
    if(!found_next) branches.push_back(cur_size);
}

ll solve(vvi & graph, vi& indegree, int n){
    queue<int> q;
    rep1(i, n){
        if(indegree[i] == 1) q.push(i);
    }
    int diameter = 0;
    int centre_node = q.front();
    while(!q.empty()){
        int sz = q.size();
        if(sz == 1){
            diameter ++;
            centre_node = q.front();
            break;
        }
        while(sz--){
            int u = q.front();
            centre_node = u;
            indegree[u]--;
            q.pop();
            for(auto& v: graph[u]){
                indegree[v]--;
                if(indegree[v] == 1) q.push(v);
            }
        }
        diameter += 2;
    }
    ll ans = 0;

    
    vi branches;
    vb visited(n+1);
    visited[centre_node] = true;

    dfs(branches, graph, visited, centre_node);

    int diameter_branch1 = (diameter-1)/2;
    int diameter_branch2 = diameter - 1 - diameter_branch1;

    sort(all(branches));

    rep(i, n){
        if(branches[i] == diameter_branch1){
            branches.erase(branches.begin() + i);
            break;
        }
    }
    rep(i, n){
        if(branches[i] == diameter_branch2){
            branches.erase(branches.begin() + i);
            break;
        }
    }

    ll total_sum = accumulate(all(branches), 0ll);

    rep(i, branches.size()){
        ans += branches[i]*(total_sum-branches[i]);
    }

    ans /=2;
    ans += 1ll*diameter*(diameter+1)/2;
    return ans;

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
        cout << solve(graph, indegree, n) << endl;
    }
    return 0;
}