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
// #define endl "\n"
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

enum Count {
    even,
    odd
};

inline pair<bool, bool> get_prev_states(bool count_a, bool count_b){
    return {count_a^1, count_b};
}

void solve(int& ans, char a, char b, string& s, int k, int n){
    int left = -1;
    int left_freq_a = 0, left_freq_b = 0;
    int right_freq_a = 0, right_freq_b = 0;

    vvi min_count(2, vi(2, INT_MAX));
    rep(right, n){
        if(s[right] == a) right_freq_a++;
        if(s[right] == b) right_freq_b++;

        while((right - left) >=k && (right_freq_a - left_freq_a) >=1 && (right_freq_b - left_freq_b) >=2){
            amin(min_count[left_freq_a%2][left_freq_b%2], left_freq_a - left_freq_b);

            left++;
            if(s[left] == a) left_freq_a++;
            if(s[left] == b) left_freq_b++;
        }

        auto [prev_state_a, prev_state_b] = get_prev_states(right_freq_a%2, right_freq_b%2);
        if(min_count[prev_state_a][prev_state_b] != INT_MAX)
            amax(ans, right_freq_a - right_freq_b - min_count[prev_state_a][prev_state_b]);
    }
}

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        rep(a, 5){
            rep(b, 5){
                if(a == b) continue;
                solve(ans, a+'0', b+'0', s, k, n);
            }
        }
        return ans;
    }
};