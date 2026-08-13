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

bool valid_idx(int start, int sz, int val)
{
    return (val >= start && val < start + sz);
}

bool search(int max_ele, int min_ele, vi &a, int n)
{
    // i have to search for segemt start = max_ele + 1 to start + right - left
    int sz = max_ele - min_ele + 1;
    int bleft = 0, bright = 0;
    vector<bool> present(sz);
    int start = max_ele + 1;
    int present_count = 0;
    while (bright < n)
    {
        if (valid_idx(start, sz, a[bright]))
        {
            while (bleft < bright && present[a[bright] - start])
            {
                if (start, sz, a[bleft])
                {
                    present[a[bleft] - start] = false;
                    present_count--;
                }
                bleft++;
            }

            present[a[bright] - start] = true;
            present_count++;
            if (present_count == sz)
                return true;
        }
        else
        {
            while (bleft <= bright)
            {
                if (valid_idx(start, sz, a[bleft]))
                {
                    present[a[bleft] - start] = false;
                    present_count--;
                }
                bleft++;
            }
        }
        bright++;
    }
    return false;
}

int solve(vi &a, int n)
{
    int ans = 0;
    for (int start = 1; start <= n; start++)
    {
        vector<bool> present(n + 1);
        for (int sz = 1; sz <= n / 2; sz++)
        {
            int a_min_ele = start, a_max_ele = start + sz - 1;
            int b_start = start + sz;
            int b_min_ele = b_start, b_max_ele = b_start + sz - 1;
            if (search(a_max_ele, a_min_ele, a, n) && search(b_max_ele, b_min_ele, a, n))
                amax(ans, sz);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream &in = getInputStream();
    int t;
    in >> t;
    while (t--)
    {
        int n;
        in >> n;
        vi a(n);
        rep(i, n) in >> a[i];
        cout << solve(a, n) << endl;
    }
    return 0;
}