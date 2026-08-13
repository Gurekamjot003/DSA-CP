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

vi odd_size_palindrome(vi num_first_half){
    queue<int> q;
    int n = num_first_half.size();
    for(int i = n-2; i>=0; i--){
        int last_dig = num_first_half[i];
        q.push(last_dig);
    }
    while(!q.empty()){
        num_first_half.push_back(q.front());
        q.pop();
    }
    return num_first_half;
}

vi even_size_palindrome(vi num_first_half){
    queue<int> q;
    int n = num_first_half.size();
    for(int i = n-1; i>=0; i--){
        int last_dig = num_first_half[i];
        q.push(last_dig);
    }
    while(!q.empty()){
        num_first_half.push_back(q.front());
        q.pop();
    }
    return num_first_half;
}

ll calculate_decimal(vi& k_mirror, int k){
    ll ans = 0;
    int n = k_mirror.size();
    for(int i = n - 1; i>=0; i--){
        ans = ans * k + k_mirror[i];
    }
    return ans;
}

bool is_palindrome(ll decimal){
    ll rev = 0;
    ll temp = decimal;
    while(temp){
        rev = rev*10 + temp%10;
        temp/=10;
    }
    return rev == decimal;
}

void backtrack(int digits, int k, bool odd, vi& num_first_half, ll& ans, int& total_nums_req){
    if(total_nums_req == 0) return;
    if(digits == 0){
        vi k_mirror = (odd? odd_size_palindrome(num_first_half): even_size_palindrome(num_first_half));
        ll decimal_value = calculate_decimal(k_mirror, k);
        if(is_palindrome(decimal_value)){
            ans += decimal_value;
            total_nums_req--;
        }
        return;
    }
    rep(i, k){
        if(num_first_half.empty() && i == 0) continue;
        num_first_half.push_back(i); 
        backtrack(digits-1, k, odd, num_first_half, ans, total_nums_req);
        num_first_half.pop_back(); 
    }
}

class Solution {
public:
    long long kMirror(int k, int n) {
        vi num_first_half;
        bool odd = true;
        int digits = 1;
        ll ans = 0;
        while(n){
            backtrack(digits, k, odd, num_first_half, ans, n);
            if(odd == false) digits++;
            odd ^= 1;
        }
        return ans;
    }
};
