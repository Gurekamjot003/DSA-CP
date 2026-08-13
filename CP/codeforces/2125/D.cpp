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

const int mod = 998244353;

ll none_selected_prob(vvi& segments, int n){
    ll ans = 1;
    for(auto& segment: segments){
        ll p = segment[2], q = segment[3];
        ll num = q-p;
        
        num *= modInverse(q, mod);
        num%=mod;
        ans *= num;
        ans%= mod;
    }
    return ans;
}

int bs(vvi& segments, int target){
    int left = 0, right = segments.size()-1;
    int ans = INT_MAX;
    while(left<=right){
        int mid = (left+right)/2;
        if(segments[mid][0] == target){
            ans = mid; 
            right = mid-1;
        }
        else if(segments[mid][0] >target) right = mid-1;
        else left = mid+1;
    }
    return ans;
}

ll calculate(vvi& segments, int n, int m, vll& dp, int i = 1){
    if(i == m+1) return 1;

    if(dp[i] != -1) return dp[i];
    
    int seg_idx = bs(segments, i);
    ll ans = 0;
    while(seg_idx < n && segments[seg_idx][0] == i){
        ll p = segments[seg_idx][2], q = segments[seg_idx][3];
        ll prob = p;
        prob *= modInverse(q-p, mod);
        prob%=mod;
        prob *= calculate(segments, n,m, dp, segments[seg_idx][1]+1);
        prob%=mod;
        ans += prob;
        ans%=mod;
        seg_idx++;
    }
    return dp[i] = ans;

}

int solve(vvi& segments, int n, int m){
    sort(all(segments));
    vll dp(m+1, -1);
    ll ans =none_selected_prob(segments, n);
    ans *= calculate(segments, n, m, dp);
    ans %= mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int n, m; in>>n>>m;
    vvi segment(n);
    rep(i, n){
        int l, r, p, q;
        in>>l>>r>>p>>q;
        segment[i] = {l, r, p, q};
    }
    cout<<solve(segment, n, m);
    return 0;
}