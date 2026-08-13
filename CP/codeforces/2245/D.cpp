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

pair<bool, vi> solve(vvi& restrictions, int n, int m){
    vvi graph(n+1);
    vi pos(n+1);
    
    for(auto& r: restrictions){
        int i = r[1], j = r[2], o = r[0];
        if(i == j){
            if(o == 1) pos[i] = 1;
            else pos[i] = 2;
        }
    }
    vi indegree(n+1);
    for(auto& r: restrictions){
        int i = r[1], j = r[2], o = r[0];
        if(i == j) continue;
        
        if((o==1 && (pos[i] == 2 && pos[j] == 2)) or (o ==2 && (pos[i] == 1 && pos[j] == 1))) return {false, {}};
        if((o == 1 && (pos[i] == 1 && pos[j] == 1)) or (o == 2 && (pos[i] == 2 && pos[j] == 2))) continue;

        if(pos[i] == 0 && pos[j] != 0)
        if((o == 1 && pos[i] == 1) or (o == 2 && pos[i] == 2)){
            graph[j].push_back(i);
            indegree[i]++;
        }
        else{
            graph[i].push_back(j);
            indegree[j]++;
        }
    }
    queue<int> q;
    rep1(i, n){
        if(indegree[i] == 0) q.push(i);
    }
    vi ans(n+1, 1);

    // vb visited(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto& v: graph[u]){
            indegree[v]--;
            amax(ans[v], ans[u] + 1);
            if(indegree[v] == 0) q.push(v);
        }
    }

    for(auto& n: indegree) if(n) return {false, {}};
    rep1(i, n){
        if(!pos[i]) ans[i] *= -1;
    }
    ans.erase(ans.begin());
    return {true, ans};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int m; in>>m;
        vvi restrictions(m, vi(3));
        rep(i, m){
            rep(j, 3) in>>restrictions[i][j];
        }
        auto[y, ans] = solve(restrictions, n, m);
        yn(y);
        if(y){
            for(auto& n: ans) cout<<n<<" ";
            cout<<endl;
        }
        // cout << result << endl;
    }
    return 0;
}