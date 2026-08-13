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
#define endl "\n"
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

ll multiply(ll a, ll b, ll mod){
    while(b){
        
        a = (a*2)%mod;
        b/=2;
        
    }
    return a;
}


const int mod = 1e9 + 7;

int bfs(vvi & graph, vb& visited, int u){
    queue<int> q; 
    q.push(u);
    visited[u] = true;
    int ans = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans++;
        for(auto& v: graph[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
        if(q.size() >1) return -1;
    }
    return ans;
    
}

int solve(vvi & graph, int n, vi& indegree){
    vb visited(n+1);
    queue<int> q;
    int common_path = 0;
    q.push(1);
    visited[1] = true;
    while(q.size() == 1){
        int u = q.front();
        q.pop();
        for(auto& v: graph[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
        common_path++;
    }

    if(!q.empty()){
        if(q.size() >2) return 0;
        int path_1 = bfs(graph, visited, q.front());
        q.pop();
        if(path_1 == -1) return 0;
        int path_2 = bfs(graph, visited, q.front());
        q.pop();
        if(path_2 == -1) return 0;

        int diff = abs(path_1 - path_2);
        ll ans = (diff == 0? 2: power(2, diff, mod) + power(2, diff-1, mod));
        while(common_path--){
            ans = (ans * 2)%mod;
        }
        return ans;
    }
    return power(2, common_path, mod);

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
        // Your logic here
        cout << solve(graph, n, indegree) << endl;
    }
    return 0;
}