// we are given n and prime p we have to return nth fibo mod p
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

#define vvll vector<vll>

vvll matrix_mul(vvll& m1, vvll& m2, ll mod){
    int m = m1.size(), n = m1[0].size(), o = m2[0].size();
    vvll ans(m, vll(o));
    rep(i, m){
        rep(j, o){
            rep(k, n){
                ans[i][j] += m1[i][k]*m2[k][j]%mod;
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}

vvll matrix_exp(vvll& m, ll power, ll mod){
    vvll ans(m.size(), vll(m.size()));
    rep(i, m.size()) ans[i][i] = 1; // set ans matrix to I

    while(power){
        if(power%2) ans = matrix_mul(ans, m, mod);
        m = matrix_mul(m, m, mod);
        power/=2;
    }
    return ans;
}

ll solve(ll n, ll p){
    vvll m = {{1, 1}, {1, 0}};
    vvll base = {{1},{0}};
    m = matrix_exp(m, n-2, p);
    vvll final_mat = matrix_mul(m, base, p);
    return final_mat[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    ll n; in >> n;
    ll p; in>>p;

    cout << solve(n, p) << endl;
    
    return 0;
}