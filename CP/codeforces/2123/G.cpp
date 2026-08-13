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

void push_into_modulo(vi& a, int n, int g, map<int, int>& modulo_array){
    if(g == 1 or modulo_array.count(g)){ // coprime
        return;
    }
    int break_point = 0;
    rep1(i, n){
        if((a[i]%g)<(a[i-1]%g)) break_point++;
    }
    modulo_array[g] = break_point;
}

void solve(vi& a, int n, int m, int q, vvi& queries){
    map<int, int> break_points_mp;
    for(int k = 1; k*k<=m; k++){
        int g = gcd(k, m);
        push_into_modulo(a, n, g, break_points_mp);
        push_into_modulo(a, n, m/g, break_points_mp);
    }

    for(auto& query: queries){
        int type = query[0];
        if(type == 1){
            int i = query[1], x = query[2];
            for(auto& it: break_points_mp){
                auto&break_points = it.second;
                int g = it.first;
                int old_val = a[i]%g;
                //before scene
                int old_dip_count = 0;
                if(old_val<(a[i-1]%g)) old_dip_count++;
                if(i<n && (a[i+1]%g)<old_val) old_dip_count++;
                
                int new_dip_count = 0;
                if((x%g)<(a[i-1]%g)) new_dip_count++;
                if(i<n && (a[i+1]%g)<(x%g)) new_dip_count++;
                
                int diff = new_dip_count-old_dip_count;
                break_points += diff;
            }
            a[i] = x;
        }
        else{
            bool ans = false;
            int k = query[1];
            int g = gcd(k, m);
            if(g==1){
                ans = true;
            }
            else{
                int max_count = m/g;
                if(break_points_mp[g] < max_count) ans = true;
            }
            yn(ans);
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        int m ,q; in>>m>>q;
        vi a(n+1);
        rep1(i, n) in>>a[i];
        vvi queries;
        rep(_, q){
            int type; in>>type;
            queries.push_back({type});
            if(type == 1){
                int i, x;
                in>>i>>x;
                queries.back().push_back(i);
                queries.back().push_back(x);
            }
            else{
                int k;
                in>>k;
                queries.back().push_back(k);
            }
        }
        solve(a, n, m, q, queries);
        // cout << result << endl;
    }
    return 0;
}