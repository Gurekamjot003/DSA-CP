#include <bits/stdc++.h>
using namespace std;

// Macros
#define ld long double
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
#define vvll v<v<ll>>
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

ld find_greatest(ld a, ld b, ld c, ld d){
    return max(a, max(b, max(c, d)));
}

ll solve(ll n, ll m, ll a, ll b){
    int ans = INT_MAX;
    if((b-1)>(m-b)) b = m-b+1;
    if((a-1)>(n-a)) a = n-a+1;
    v<pair<ll, ll>> sol = {{a, m}, {n, b}};
    for(auto& p : sol){
        ll bottom = p.first, right = p.second;
        ll left = 1, top = 1;
        int cur = 1;
       
        int num_columns = right - left + 1;
        while(num_columns>1){
            num_columns = (num_columns + 1)/2;
            cur++;
        }
        int num_rows = bottom - top + 1;
        while(num_rows>1){
            num_rows = (num_rows + 1)/2;
            cur++;
        }
        ans = min(ans, cur);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, m, a, b; 
        in >> n>>m>>a>>b;
        
        // Your function call here
        cout << solve(n, m, a, b) << endl;
    }

    return 0;
}