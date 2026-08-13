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

void display(vi& nums){
    for(auto&n: nums) cout<<n<<" ";
    cout<<endl;
}
void display(vvi& nums){
    for(auto&m: nums){
        for(auto&n: m) cout<<n<<" ";
        cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n =mat.size(), m = mat[0].size();
        vvi right(n+1, vi(m+1));
        vvi down = right, sq = right;
        vi max_sq_ahead(m);
        vi max_sq_cur(m);
        int max_sq = 0;
        for(int j = m-1; j>=0; j--){
            int cur_sq = 0;
            for(int i = n-1; i>=0; i--){
                if(mat[i][j]){
                    right[i][j] = 1+right[i][j+1];
                    down[i][j] = 1+down[i+1][j];
                    sq[i][j] = min(right[i][j], min(down[i][j], 1+sq[i+1][j+1]));
                    amax(cur_sq, sq[i][j]);
                }
            }
            amax(max_sq, cur_sq);
            max_sq_ahead[j] = max_sq;
            max_sq_cur[j] = cur_sq;
        }
        
        int ans = 0;
        rep(i, m-1){
            for(int j = i+1; j<m; j++){
                int k = j-i;
                if(max_sq_cur[i]>=k && max_sq_ahead[j]>=k) amax(ans, k);
            }
        }
        vi max_sq_ahead_down(n), max_sq_cur_down(n);
        max_sq = 0;
        for(int i = n-1; i>=0; i--){
            int cur_sq = 0;
            for(int j = m-1; j>=0; j--){
                amax(cur_sq, sq[i][j]);
            }
            amax(max_sq, cur_sq);
            max_sq_ahead_down[i] = max_sq;
            max_sq_cur_down[i] = cur_sq;
        }
        rep(i, n-1){
            for(int j = i+1; j<n; j++){
                int k = j-i;
                if(max_sq_cur_down[i]>=k && max_sq_ahead_down[j]>=k) amax(ans, k);
            }
        }
        return ans*ans;
    }
};