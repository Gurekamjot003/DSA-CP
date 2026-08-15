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

class Solution
{
public:
    int kthDigit(long long k)
    {
        ll cur = 0;

        int i = 1;
        for (; i <= 15; i++)
        {
            ll max_val = power(10ll, i, INT64_MAX) - power(10ll, i - 1, INT64_MAX);
            ll to_sub = max(0ll, min(((k - 1) / i), max_val));
            // cout << max_val << " " << to_sub << endl;
            k -= to_sub * i;
            cur += to_sub;
            // cout << k << endl;
            if (k <= i)
                break;
        }
        // cout << cur << endl;
        string s = "0" + to_string(cur + 1);
        // cout << s << endl;

        if ((s[s.size() - 2] - '0') % 2)
            s.back() = '9' - s.back() + '0';
        // cout << k << endl;
        return s[k] - '0';
    }
};

// int main()
// {
//     Solution sol;
//     cout << sol.kthDigit(12) << endl;
// }