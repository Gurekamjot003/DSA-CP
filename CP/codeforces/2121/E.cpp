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

vi digitify(int n){
    vi ans;
    while(n){
        ans.push_back(n%10);
        n/=10;
    }
    return ans;
}

int get_ans(vi& l_digits, vi&r_digits, int min_val, int max_val, int n, int i = 0){
    if(i>=n) return 0;
    if(max_val - min_val > 1) return 0;
    if(min_val == max_val) return 2 + get_ans(l_digits, r_digits, l_digits[i+1], r_digits[i+1], n, i+1);
    return 1 + min(get_ans(l_digits, r_digits, l_digits[i+1], 10, n, i+1), get_ans(l_digits, r_digits, -1, r_digits[i+1], n, i+1));
}

int solve(int l, int r){
    vi l_digits = digitify(l), r_digits = digitify(r);
    reverse(all(l_digits));
    reverse(all(r_digits));
    int n = l_digits.size();
    l_digits.push_back(0);
    r_digits.push_back(0);
    int min_val = l_digits[0], max_val = r_digits[0];
    return get_ans(l_digits, r_digits, min_val, max_val, n);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int l, r; 
        in>>l>>r;
        // Your logic here
        cout << solve(l, r) << endl;
    }
    return 0;
}