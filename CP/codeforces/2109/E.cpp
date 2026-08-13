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
#define vvvi v<v<v<int>>>
#define vvvvi v<v<v<v<int>>>>

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

int mod = 998244353;

int solve(vvvvi& dp, string& s, int index, int k, bool flip = 0, bool flipped_once = 0){
    if(k == 0){
        return 1;
    }
    if(index<0){
        return 0;
    }
    if(dp[index][k][flip][flipped_once] != -1) return dp[index][k][flip][flipped_once];
    int ans = solve(dp, s, index-1, k, flip, flipped_once);    // skip

    if(flipped_once && flip != (s[index]-'0')) ans = (ans + solve(dp, s, index, k-1, !flip, 0));
    else ans = (ans + solve(dp, s, index-1, k-1, !flip, 1))%mod;
    return dp[index][k][flip][flipped_once] = ans;
}

int binary_string_wowee(string& s, int n, int k){
    bool flip = 0;
    vvvvi dp(n, vvvi(k+1, vvi(2, vi(2, -1))));
    int i = n-1;
    while(i>=0 && s[i] == '1') i--;
    int ans = solve(dp, s, i, k);
    // for(auto& n: dp){
    //     for(auto& m: n){
    //         for(auto& o: m) cout<<o<<",";
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, k; in >> n>>k;
        string s; in>>s;
        // Your function call here
        cout << binary_string_wowee(s, n, k) << endl;
    }

    return 0;
}