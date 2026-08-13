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

const int mod = 1e9 + 7;

void calc(vvi& dp, int n, vvi& matrix){
    int mid = n/2;
    dp[0][0] = 1;
    rep(i, mid){
        
        vi new_diff_freq(2*n+1);
        rep(j, n){
            if(matrix[i][j])
            rep(k, n){

                if(matrix[i+mid][k]){
                    new_diff_freq[j-k + n]++;
                }
            }
        }

        rep(j, dp[i].size()){
            if(dp[i][j] == 0) continue;
            rep(d, new_diff_freq.size()){
                int new_diff = j+d-n;
                if(new_diff<0 or new_diff>=dp[i+1].size()) continue;
                dp[i+1][new_diff] = (dp[i+1][new_diff] + 1ll*new_diff_freq[d]*dp[i][j])%mod;
            }
        }
    }

}

ll solve(vvi& matrix, int n){
    int mid = n/2;
    ll ans = 1;
    for(auto& m: matrix){
        ll cur = accumulate(all(m), 0ll);
        ans *= cur;
        ans%=mod;
    }


    vvi dp(mid+1, vi(n*n+1));
    calc(dp,n, matrix);
    ll cycles = dp.back()[0];
    ans -= cycles;
    ans += mod;
    ans%= mod;
    return ans;
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vvi matrix(n, vi(n));
        rep(i, n){
            string s; in>>s;
            rep(j, n){
                matrix[i][j] = s[j]-'0';
            }
        }
        cout << solve(matrix, n) << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}