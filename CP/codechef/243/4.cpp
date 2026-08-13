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

void print(vi &a)
{
    for (auto &n : a)
        cout << n << " ";
    cout << endl;
}

int arr_gcd(vi &a, int start, int end)
{
    int ans = a[start];
    for (int i = start + 1; i <= end; i++)
    {
        ans = gcd(ans, a[i]);
    }
    return ans;
}

bool check(vi &a)
{
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (j - i == n - 1)
            {
                if (arr_gcd(a, i, j) != 1)
                    return false;
            }
            else if (arr_gcd(a, i, j) == 1)
                return false;
        }
    }
    return true;
}

pair<int, vvi> tester(int n, int m)
{
    int ans = 0;
    vvi ans_arr;
    if (n <= 5)
    {
        vi cur;
        for (int i = 2; i <= m; i++)
        {
            cur.push_back(i);
            for (int j = 2; j <= m; j++)
            {
                cur.push_back(j);
                for (int k = 2; k <= m; k++)
                {
                    cur.push_back(k);
                    if (n > 3)
                    {
                        for (int l = 2; l <= m; l++)
                        {
                            cur.push_back(l);
                            if (n == 5)
                            {
                                for (int o = 2; o <= m; o++)
                                {
                                    cur.push_back(o);
                                    if (check(cur))
                                    {
                                        ans_arr.push_back(cur);
                                        ans++;
                                    }
                                    cur.pop_back();
                                }
                            }
                            else if (check(cur))
                            {
                                ans_arr.push_back(cur);
                                ans++;
                            }
                            cur.pop_back();
                        }
                    }
                    else
                    {
                        if (check(cur))
                        {
                            ans_arr.push_back(cur);
                            ans++;
                        }
                    }
                    cur.pop_back();
                }
                cur.pop_back();
            }
            cur.pop_back();
        }
    }
    return {ans, ans_arr};
}
vi primes = prime_numbers_upto(101);

void precompute(vi& dp, int m, int e){
    for(int i = m; i>=2; i--){
        dp[i] = power(m/i, e, mod);
        for(int j = 2; i*j <= m; j++)
            dp[i] = (dp[i] - dp[i*j] + mod)%mod;
    }
}

int solve(int n, int m)
{
    vi dp(m+1);
    precompute(dp, m, n-2);
    long long ans = 0;
    for (int i = 2; i <= m; i++)
    {
        for (int j = i+1; j <= m; j++)
        {
            for(int k = 2; k<=m; k++){
                if(gcd(k, gcd(i, j)) == 1 && gcd(i, k) != 1 && gcd(j, k) != 1) 
                    ans = (ans + 2*dp[k])%mod;
            }
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
        int m;
        in >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}