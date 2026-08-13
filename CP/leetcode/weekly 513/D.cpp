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
#define all(x) x.begin(), x.end()
#define yn(x) cout << (x ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define rev(i, n, step) for (int i = n - 1; i >= 0; i -= step)

template <typename T>
void amin(T &a, T b) { a = min(a, b); }
template <typename T>
void amax(T &a, T b) { a = max(a, b); }

template <typename T>
T gcd(T a, T b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b)
    {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

template <typename T>
T lcm(T a, T b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

vector<int> prime_numbers_upto(int n)
{
    vector<bool> is_prime(n + 1, true);
    vi ans;
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
            continue;
        ans.push_back(i);
        for (int j = i * 2; j <= n; j += i)
            is_prime[j] = false;
    }
    return ans;
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod)
{
    return power(a, mod - 2, mod);
}

istream &getInputStream()
{
    static ifstream file("input.txt");
    return (file.is_open() ? file : cin);
}
#endif

template <class T>
class SegmentTree
{
public:
    vector<T> tree;
    vector<T> data;

    T init(int index)
    {
        return data[index];
    }

    T combine(T val_1, int val_2)
    {
        return val_1 + val_2;
    }

    void update_helper(int target_index, int left, int right, int index = 0)
    {
        if (left == right)
        {
            tree[index] = init(target_index);
            return;
        }
        int mid = (left + right) / 2;
        int left_child = index * 2 + 1, right_child = index * 2 + 2;
        if (target_index <= mid)
            update_helper(target_index, left, mid, left_child);
        else
            update_helper(target_index, mid + 1, right, right_child);

        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    T query_helper(int q_left, int q_right, int left, int right, int index = 0)
    {
        if (left >= q_left && right <= q_right)
            return tree[index];
        if (left > q_right or right < q_left)
            return (T)0;
        int mid = (left + right) / 2;
        int left_child = index * 2 + 1, right_child = index * 2 + 2;
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid + 1, right, right_child));
    }

public:
    SegmentTree(vector<T> &data)
    {
        int sz = data.size();
        tree.resize(sz * 4);
        this->data = data;
        int left = 0, right = data.size() - 1;
        build(data, left, right);
    }

    void build(vector<T> &data, int left, int right, int index = 0)
    {
        if (left == right)
        {
            tree[index] = init(left);
            return;
        }
        int mid = (left + right) / 2;
        int left_child = index * 2 + 1, right_child = index * 2 + 2;
        build(data, left, mid, left_child);
        build(data, mid + 1, right, right_child);

        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    void update(int data_index, T value)
    {
        data[data_index] = value;
        update_helper(data_index, 0, data.size() - 1);
    }

    T get_value(int q_left, int q_right)
    {
        return query_helper(q_left, q_right, 0, data.size() - 1);
    }
};

class Solution
{
public:
    long long countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        int n = nums.size();
        // step 1 nums to -a on odd, +b on even array
        rep(i, n) nums[i] = (nums[i] % 2 ? -a : +b);
        // step 2 convert to pref_sum
        vll pref_sum(n + 1);
        rep1(i, n)
        {
            pref_sum[i] += nums[i - 1] + pref_sum[i - 1];
        }

        // step 3 rank the pref_sum values to put into seg tree
        vll t = pref_sum;
        sort(all(t));
        unordered_map<ll, int> rank;
        rep(i, n + 1)
        {
            rank[t[i]] = i;
        }

        // step 4 segment tree insertion
        // we have to count pref_sum < current value on the lhs to get +ve sum
        ll ans = 0;
        vector<ll> data(n + 1);
        SegmentTree st(data);
        rep(i, n + 1)
        {
            int idx = rank[pref_sum[i]];
            st.update(idx, ++data[idx]);
            int left = rank[t[0]], right = idx - 1;
            ans += st.get_value(left, right);
        }

        // step 5 return required ans
        ans = 1ll * n * (n + 1) / 2 - ans;
        return ans;
    }
};