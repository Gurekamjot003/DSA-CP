#include <bits/stdc++.h>
using namespace std;

// Macros
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
#define v vector
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
#define endl "\n"

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

// Function to get input stream based on file availability
istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}

bool possible(ll max_batteries, vi& batteries, vvpii& graph, int n){
    vll dp(n+1, -1);
    dp[1] = 0;

    for(int i = 1; i<=n; i++){
        if(dp[i] == -1) continue;
        dp[i] += batteries[i];
        dp[i] = min(dp[i], max_batteries);
        for(auto& edge: graph[i]){
            ll neighbor = edge.first, required = edge.second;
            if(required<=dp[i]) dp[neighbor] = max(dp[neighbor], dp[i]);
        }
    }

    return dp[n] != -1;
}

int fewer_batteries(vi& batteries, vvpii& graph, int n){

    ll left = 0, right = accumulate(all(batteries), 0ll);
    ll ans = -1;
    while(left<=right){
        ll mid = (left+right)/2;
        if(possible(mid, batteries, graph, n)){
            ans = mid;
            right = mid -1;
        }
        else left = mid+1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, m; in >> n>>m;

        vi batteries(n+1);
        for(int i = 1; i<=n; i++){
            in>>batteries[i];
        }

        vvi paths(m);
        for(int i=  0; i<m; i++){
            int s, t, w;
            in>>s>>t>>w;
            paths[i].push_back(s);
            paths[i].push_back(t);
            paths[i].push_back(w);
        }
        
        vvpii graph(n+1);
        for(auto& path: paths){
            graph[path[0]].push_back({path[1], path[2]});
        }
        // Your function call here
        cout << fewer_batteries(batteries, graph, n) << endl;
    }

    return 0;
}