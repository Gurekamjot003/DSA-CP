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

ll solve(vi &a, int n)
{
    vll normal(n);
    int max_val = a[0];
    ll max_contri = 0;
    rep1(i, n - 1)
    {
        normal[i] = max(0, max_val - a[i]) + normal[i - 1];
        amax(max_val, a[i]);
        amax(max_contri, normal[i] - normal[i - 1]);
    }

    ll ans = normal.back() - max_contri;  // convert cur ele to max in prev eles
    // equivalent to cur_ele missing

    int max1 = max(a[0], a[1]), max2 = min(a[0], a[1]);
    ll max_missing = 0;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] == max1)
            max_missing = normal[i - 2]; // prev is missing
        
        max_missing += max(0, max2 - a[i]);
        amin(ans, max_missing + (normal.back() - normal[i]));
        if (a[i] >= max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2)
        {
            max2 = a[i];
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