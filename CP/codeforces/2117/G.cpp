#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
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

ll solve(vvpii& graph, int n, int m){
    int min_weight = INT_MAX, max_weight = INT_MIN;
    priority_queue<pii, vector<pii>, greater<>> pq;

    vb visited(n+1);
    bool found = false;
    for(auto&[v, w]: graph[1]) pq.push({w, v});
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        amin(min_weight, w);
        if(visited[u]) continue;
        visited[u] = true;
        if(found && w>max_weight) continue;
        amax(max_weight, w);
        if(u == n) found = true;
        for(auto& [v, new_w]: graph[u]){
            pq.push({new_w, v});
        }
    }
    return min_weight+max_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    vi ans = {11,18,19,36,10,10,6,2,6,20,21,27,13,2,21,16,7,17};
    int ptr = 0;
    int t; in >> t;
    while (t--) {
        int n, m; in >> n>>m;
        // Your logic here
        vvi edges;
        vvpii graph(n+1);
        rep(i, m){
            int u, v, w;
            in>>u>>v>>w;
            edges.push_back({u, v, w});
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        int cur =  solve(graph, n, m);
        cout<<cur<<endl;
        if(ans[ptr++] != cur){
            cerr<<"\nWrong ans on testcase "<<ptr<<endl;
            cerr<<"Correct ans: "<<ans[ptr-1]<<" Your ans: "<<cur<<endl;
            cerr<<n<<" "<<m<<" "<<endl;
            for(auto& e: edges){
                for(auto& temp: e) cerr<<temp<<" ";
                cerr<<endl;
            }
            return 0;
        }
        
    }
    return 0;
}