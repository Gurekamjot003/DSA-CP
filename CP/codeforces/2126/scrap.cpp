#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// simple gcd
ll gcd(ll a, ll b) {
    while (b) { ll t = b; b = a % b; a = t; }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ---- CONFIGURE THESE AS YOU LIKE ----
    const int T = 1000;      // number of test cases
    const int N_MAX = 10;    // max length of each a[]
    const int VAL_MAX = 100; // max value in a[]
    // -------------------------------------

    mt19937_64 rng(chrono::high_resolution_clock::now()
                   .time_since_epoch().count());
    uniform_int_distribution<int> ndist(1, N_MAX);
    uniform_int_distribution<int> vdist(1, VAL_MAX);

    cout << T << "\n";
    for (int tc = 0; tc < T; tc++) {
        int n = ndist(rng);
        vector<ll> a(n), p(n), s(n);

        // 1) generate random a[]
        for (int i = 0; i < n; i++) {
            a[i] = vdist(rng);
        }

        // 2) build prefix‑GCD p[]
        p[0] = a[0];
        for (int i = 1; i < n; i++) {
            p[i] = gcd(p[i-1], a[i]);
        }

        // 3) build suffix‑GCD s[]
        s[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            s[i] = gcd(a[i], s[i+1]);
        }

        // 4) emit test case
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << p[i] << (i+1<n?' ':'\n');
        }
        for (int i = 0; i < n; i++) {
            cout << s[i] << (i+1<n?' ':'\n');
        }

        // (optional) if you want to see the original 'a' for debugging,
        // uncomment the next two lines:
        // for (auto x : a) cerr << x << ' ';
        // cerr << "\n";
    }

    return 0;
}
