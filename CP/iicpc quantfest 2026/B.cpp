#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep1(i, n) for(int i = 1; i<=n; i++)





#include<bits/stdc++.h>
using namespace std;

ll lcm(ll a, ll b){
    ll gcd = ::gcd(a, b);
    return a*b/gcd;
}

const long long MOD = 998244353;
long long modpow(long long a, long long b) {
    long long res = 1; a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
long long modinv(long long q) { return modpow(q, MOD - 2); }

double sum(double a, double l){
    double ans = (l-a+1)*(a+l)/2;
    return ans;
}

double solve(vector<double>& a, int n){
    double ans = 0;
    for(int i = n-1; i>=0; i--){
        double min_val = min<double>(floor(ans), a[i]);
        if(min_val >= a[i]) continue;
        double cur = sum(min_val+1, a[i]);
        double new_ans = ans*min_val + cur;
        ans = (new_ans+0.0)/a[i];
    }
    return ans;
}

int main(){
    cin.tie(0);
    int n; cin>>n;
    vector<double> a(n);
    rep(i, n) cin>>a[i];
    double ans = solve(a, n);
    cout<<ans<<endl;
    return 0;
}