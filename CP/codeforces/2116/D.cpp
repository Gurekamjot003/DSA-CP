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

bool evaluate(vi a, vi& b, int n, int q, vvi& queries){
    for(auto& query: queries){
        int x = query[0], y = query[1], z = query[2];
        a[z] = min(a[x], a[y]);
    }
    return (a == b);
}

vi solve(vvi& queries, vi& b, int n, int q){
    vi min_val = b;
    for(int i = (q-1); i>=0; i--){
        auto& query = queries[i];
        int x = query[0], y=query[1], z= query[2];
        int temp = min_val[z];
        min_val[z] = -1;
        amax(min_val[x],temp);
        amax(min_val[y],temp);
    }
    rep1(i, n){
        if(min_val[i] == -1) min_val[i] = 1;
    }
    if(!evaluate(min_val, b, n, q, queries)) return {-1};
    return min_val;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n,q ; in >> n>>q;

        vi b(n + 1); rep1(i, n) in>>b[i];

        vvi queries; 
        rep(i, q){
            vi temp(3);
            rep(j, 3) in>>temp[j];
            queries.push_back(temp);
        }
        // Your logic here
        vi ans = solve(queries, b, n, q);
        if(ans[0] == -1) cout<<ans[0];
        else rep1(i, n) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}