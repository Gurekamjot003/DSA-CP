#include <bits/stdc++.h>
using namespace std;

// Macros
#define ll long long
#define pii pair<int, int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define v4i vector<vector<vector<vector<int>>>>
#define vvll vector<vector<ll>>
#define vvvll vector<vector<vector<ll>>>
#define v4ll vector<vector<vector<vector<ll>>>>
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

ll solve(v4ll& dp,vi& a, vi& b, int n, int k, int i = 1, bool started = 0, bool gap = 0, bool one_present = 0, ll sum = 0){
    if(i>n){
        if(started and gap){
            return 0;
        }
        return (ll)1e18;
    }
    if(dp[i][started][gap][one_present] != -1) return dp[i][started][gap][one_present];
    ll pick = solve(dp, a, b, n, k, i+1, 1, gap, one_present | b[i], sum + a[i]);
    if(gap){
        if(sum>=k) return 0;
        if(one_present) return k - (sum + a[i]);
    }

    ll skip = solve(dp, a, b, n, k, i+1, started, started, one_present, sum);
    
    return dp[i][started][gap][one_present] = min(pick, skip);
}

ll anti_subarray_sum(vi& a, vi& b, int n, int k){
    v4ll dp(n+1, vvvll(2, vvll(2, vll(2, -1))));
    return max(0ll, solve(dp, a, b, n, k));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        ll x; in>>x;
        vi a(n+1), b(n+1);
        for(int i = 1; i<=n; i++) in>>a[i];
        for(int i = 1; i<=n; i++) in>>b[i];
        
        // Your function call here
        cout << anti_subarray_sum(a, b, n, x) << endl;
    }

    return 0;
}