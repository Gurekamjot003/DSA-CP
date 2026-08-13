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
#define yn(x) cout<<(x?"YES":"NO")<<'\n'
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep1(i, n) for(int i = 1; i<=n; i++)
#define rev(i, n, step) for(int i = n-1; i>=0; i-= step)

using namespace std;

class BIT {
    int n, K;
    vi bit_a, bit_b, bit_diff;

    // point-update of Fenwick tree
    void update_bit(vi &bit, int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    // prefix-sum of Fenwick tree
    int prefix_sum(const vi &bit, int idx) const {
        int s = 0;
        while (idx > 0) {
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    }

    // find smallest index i with prefix_sum(bit, i) >= target
    int fenw_find_kth(const vi &bit, int target) const {
        int pos = 0;
        int LOG = 31 - __builtin_clz(n);
        for (int pw = 1 << LOG; pw > 0; pw >>= 1) {
            if (pos + pw <= n && bit[pos + pw] < target) {
                target -= bit[pos + pw];
                pos += pw;
            }
        }
        return pos + 1;
    }

public:
    // a and b are 1-indexed vectors of size n+1
    BIT(const vi &a, const vi &b, int kVal) : n((int)a.size()-1), K(kVal) {
        bit_a.assign(n+1, 0);
        bit_b.assign(n+1, 0);
        bit_diff.assign(n+1, 0);

        // build all three Fenwicks in O(n log n)
        for (int i = 1; i <= n; i++) {
            update_bit(bit_a,    i, a[i]);
            update_bit(bit_b,    i, b[i]);
            int flag = (abs(a[i] - b[i]) > K) ? 1 : 0;
            update_bit(bit_diff, i, flag);
        }
    }

    // update A[idx] += delta  (if you need dynamic updates)
    void updateA(int idx, int delta) {
        update_bit(bit_a, idx, delta);
        // optionally recompute bit_diff at idx if A[idx] changed by delta
    }

    // update B[idx] += delta
    void updateB(int idx, int delta) {
        update_bit(bit_b, idx, delta);
        // optionally recompute bit_diff at idx if B[idx] changed by delta
    }

    // basic prefix-sums
    int sumA(int idx) const { return prefix_sum(bit_a, idx); }
    int sumB(int idx) const { return prefix_sum(bit_b, idx); }

    // returns smallest j > idx with |a[j] - b[j]| > K, or -1 if none
    int left_most_fixed_value(int idx) const {
        int seen = prefix_sum(bit_diff, idx);
        int total_bad = prefix_sum(bit_diff, n);
        if (seen == total_bad) return -1;
        // want the (seen+1)-th bad position
        return fenw_find_kth(bit_diff, seen + 1);
    }
};
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // example usage:
    int n = 5, K = 3;
    vi a = {0, 5, 2, 9, 4, 7};  // 1..5
    vi b = {0, 1, 8, 3, 6, 2};
    BIT bit(a, b, K);

    cout << bit.left_most_fixed_value(0) << '\n';  // first i>0
    cout << bit.left_most_fixed_value(3) << '\n';
    return 0;
}
