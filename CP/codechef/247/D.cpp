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

const int mod = 998244353;

int solve(vi &p, vi &b, int n)
{

    vi dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        int val_to_check = p[i];
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] == 1)
            {
                if (b[j] == 1)
                    amax(val_to_check, p[j]);
                else if (p[j] > val_to_check)
                    dp[i] = (dp[i] + dp[j + 1]) % mod;
                else
                    break;
            }
            else
            {
                if (b[j] == 0)
                    amin(val_to_check, p[j]);
                else if (p[j] < val_to_check)
                    dp[i] = (dp[i] + dp[j + 1]) % mod;
                else
                    break;
            }
        }
    }

    return dp[0];
}

void dfs(vi &p, vi &b, int n, set<vi> &st)
{
    if (st.count(p))
        return;
    st.insert(p);
    rep(i, n - 1)
    {
        if (b[i] != b[i + 1])
        {
            if ((b[i] == 0 && p[i] > p[i + 1]) or (b[i + 1] == 0 && p[i + 1] > p[i]))
            {
                swap(b[i], b[i + 1]);
                swap(p[i], p[i + 1]);
                dfs(p, b, n, st);
                swap(b[i], b[i + 1]);
                swap(p[i], p[i + 1]);
            }
        }
    }
}

int slow_solve(vi &p, vi &b, int n)
{
    set<vector<int>> st;
    dfs(p, b, n, st);
    return st.size();
}

int num_generator(int start, int end)
{
    int n = end - start + 1;
    return start + rand() % n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream &in = getInputStream();
    // int t;
    // in >> t;
    srand(0);
    int t = 1000;
    while (t--)
    {
        int n = 10;
        vi p(n);
        iota(all(p), 1);

        rep(t, 100)
        {
            int i = num_generator(0, n - 2);
            swap(p[i], p[i + 1]);
        }
        vi b(n);
        rep(i, n)
        {
            b[i] = num_generator(0, 1);
        }
        if (solve(p, b, n) != slow_solve(p, b, n))
        {
            cout << "Correct = " << slow_solve(p, b, n) << endl;
            cout << "my = " << solve(p, b, n) << endl;
            for (auto &n : p)
                cout << n << " ";
            cout << endl;
            for (auto &n : b)
                cout << n << " ";
            cout << endl;
            break;
        }
    }

    // while (t--)
    // {
    //     int n;
    //     in >> n;
    //     vi p(n);
    //     rep(i, n) in >> p[i];
    //     vi b(n);
    //     rep(i, n) in >> b[i];

    //     cout << solve(p, b, n) << endl;
    // }
    return 0;
}