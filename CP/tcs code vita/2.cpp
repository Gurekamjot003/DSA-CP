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

vvi get_next(string& Y){
    vvi next(Y.size(), vi(26, -1));
    for(int i = (int)Y.size()-2; i>=0; i--){
        for(int j = 0; j<26; j++){
            next[i][j] = next[i+1][j];
        }
        next[i][Y[i+1]-'a'] = i+1;
    }
    return next;
}

vvi next_normal, next_rev;

int find_max_size(string& X, string& Y, int i, bool rev){
    vi lps(X.size(), i);
    int suf = i+1, pre = i;
    while(suf<(int)X.size()){
        if(X[suf] == X[pre]) lps[suf++] = ++pre;
        else if(pre == i) suf++;
        else pre = lps[pre-1];
    }
    vector<int> lps2(Y.size());
    pre = i; suf = 0;

    int ans =  0;
    while(suf<(int)Y.size() && pre<(int)X.size()){
        if(X[pre] == Y[suf]) lps2[suf++] = ++pre;
        else if(pre == i) 
        {
            auto& next = (rev? next_rev: next_normal);
            suf = next[suf][X[i]-'a'];
            if(suf == -1) break;
        }
        else pre = lps[pre-1];

        amax(ans, pre-i);
    }

    return ans;
}

int calc(string& X, string& Y, string& rev, int cost1, int cost2, vi& dp, int i = 0){
    if(i == (int)X.size()) return 0;
    int normal = find_max_size(X, Y, i, false);
    int reverse = find_max_size(X, rev, i, true);
    
    if(dp[i] != -1) return dp[i];

    return dp[i] = min(cost1+calc(X, Y, rev, cost1, cost2, dp, i+normal), cost2 + calc(X, Y, rev, cost1, cost2, dp, i+reverse));

    
}

bool necessary_condition(string& X, string& Y){
    vi freq(26);
    for(auto& ch: Y) freq[ch-'a']++;
    for(auto& ch: X) if(!freq[ch-'a']) return false;
    return true;
}

int solve(string& X, string& Y, int cost1, int cost2){
    if(!necessary_condition(X, Y)) return -1;
    string rev = Y;
    reverse(all(rev));
    int n = (int)X.size();
    vi dp(n, -1);
    next_normal = get_next(Y);
    next_rev = get_next(rev);

    return calc(X, Y, rev, cost1, cost2, dp);
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    string X, Y;
    in>>X>>Y;
    int cost1, cost2;
    in>>cost1>>cost2;
    cout<<solve(X,Y, cost1, cost2);
    return 0;
}