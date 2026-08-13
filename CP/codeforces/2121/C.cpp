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

int solve(vvi& a, int n, int m){
    
    int max_val = 0;
    vector<pii> coordinates;
    rep(i, n){
        rep(j, m){
            if(a[i][j]>max_val){
                coordinates = {};
                max_val = a[i][j];
            }
            if(a[i][j] == max_val){
                coordinates.push_back({i,j});
            }
        }
    }
    if(coordinates.size()<=2) return max_val-1;

    vi row_freq(n), col_freq(m);
    int common_row = -1, common_col = -1;
    
    rep(i, coordinates.size()){
        auto[x, y] = coordinates[i];
        row_freq[x]++;
        if(row_freq[x]>1){
            if(common_row != -1 && common_row != x) return max_val;
            common_row = x;
        }
        col_freq[y]++;
        if(col_freq[y]>1){
            if(common_col != -1 && common_col != y) return max_val;
            common_col = y;
        }
    }
    if(common_row == -1 && common_col == -1) return max_val;
    rep(i, coordinates.size()){
        auto [x, y] = coordinates[i];
        if(x!=common_row && y!=common_col){
            if(common_row == -1) common_row = x;
            else if(common_col == -1) common_col = y;
            else return max_val;
        }
    }
    return max_val-1;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, m; in >> n>>m;
        vvi a(n, vi(m));
        rep(i, n){
            rep(j, m) in>>a[i][j];
        }
        // Your logic here
        cout << solve(a, n, m) << endl;
    }
    return 0;
}