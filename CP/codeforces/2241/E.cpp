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

vb is_perfect_square;
#define vll vector<ll>
#define vvll vector<vll>

int dfs(ll &ans, vvi &graph, vi &a, int n, int u = 1, int parent = 0)
{
    vi group_count = {0};
    int sum = 0;
    for (auto &v : graph[u])
    {
        if (v == parent)
            continue;
        int cur = dfs(ans, graph, a, n, v, u);
        if (is_perfect_square[a[u]])
            group_count.push_back(cur);
        sum += cur;
    }
    if (is_perfect_square[a[u]] && group_count.size() > 1)
    {
        group_count.push_back(n - sum - 1);
        int n = group_count.size() - 1;
        auto &nums = group_count;
        vvll dp(n + 1, vll(4, 0));
        rep(i, n + 1) dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                dp[i][j] = dp[i - 1][j] + nums[i] * dp[i - 1][j - 1];
            }
        }
        ans += dp[n][2] + dp[n][3];
    }
    return sum + 1;
}

ll solve(vvi &edges, vi &a, int n)
{
    vvi graph(n + 1);
    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    ll ans = 0;
    dfs(ans, graph, a, n);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream &in = getInputStream();
    is_perfect_square.resize(1e6 + 1);
    for (int i = 1; i * i <= 1e6 + 1; i++)
    {
        is_perfect_square[i*i] = true;
    }
    int t;
    in >> t;
    while (t--)
    {
        int n;
        in >> n;
        vi a(n + 1);
        rep1(i, n) in >> a[i];
        vvi edges(n - 1, vi(2));
        rep(i, n - 1)
        {
            rep(j, 2)
            {
                in >> edges[i][j];
            }
        }
        cout << solve(edges, a, n) << endl;
    }
    return 0;
}