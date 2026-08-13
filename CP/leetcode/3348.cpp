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

vvi power_req = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {3, 0, 0, 0}, {0, 2, 0, 0}};
vi primes = {2, 3, 5, 7};
class Solution
{
    pair<bool, vi> prime_factors(ll n)
    {
        vi ans(4);
        for (int i = 0; i < primes.size(); i++)
        {
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                ans[i]++;
            }
        }
        if (n > 1)
            return {false, {}};
        return {true, ans};
    }
    string create_string(vi p, int sz = 1)
    {
        string ans;
        for (int i = 9; i > 1;)
        {
            bool is_pos = true;
            for (int j = 0; j < 4; j++)
            {
                if (power_req[i][j] > p[j])
                    is_pos = false;
            }
            if (is_pos)
            {
                ans.push_back('0' + i);
                for (int j = 0; j < 4; j++)
                {
                    p[j] -= power_req[i][j];
                }
            }
            else
                i--;
        }
        while (ans.size() < sz)
            ans.push_back('1');
        reverse(all(ans));
        return ans;
    }

public:
    string smallestNumber(string num, long long t)
    {
        int n = num.size();
        string pos_ans;
        if (num.back() == '9')
        {
            string new_num;
            int i = n - 1;
            for (; i >= 0 && num[i] == '9'; i--)
            {
                new_num.push_back('0');
            }
            if (i >= 0)
                new_num.push_back(num[i--] + 1);
            else
                new_num.push_back('1');
            while (i >= 0)
            {
                new_num.push_back(num[i--]);
            }
            reverse(all(new_num));
            pos_ans = smallestNumber(new_num, t);
        }

        auto [pos, p] = prime_factors(t);
        if (!pos)
            return "-1";
        string min_string = create_string(p, num.size());
        if (n < min_string.size() or (n == min_string.size() && num <= min_string))
            return min_string;
        if (n == min_string.size() && min_string < num)
            min_string = "1" + min_string;
        string ans;
        for (int i = 0; i < n - 22; i++)
        {
            if (num[i] == '0')
            {
                return ans + create_string(p, n - ans.size());
            }
           
            for (int j = 0; j < 4; j++)
            {
                p[j] -= power_req[num[i] - '0'][j];
                amax(p[j], 0);
            }
            ans.push_back(num[i]);
        }
        num = num.substr(max(0, n - 22));
        n = num.size();
        bool zero_present = false;
        string ans2, cur;
        for (int i = 0; i < n; i++)
        {
            for (int j = num[i] + 1 - '0'; j <= 9; j++)
            { // find min_string for next indices if possible
                vi p_cur = p;
                cur.push_back(j + '0');
                for (int k = 0; k < 4; k++)
                {
                    p_cur[k] -= power_req[j][k];
                    amax(p_cur[k], 0);
                }
                string s = create_string(p_cur, n - cur.size());

                s = cur + s;
                if (ans2.size() == 0 or ans2.size() > s.size() or (ans2.size() == s.size() && s < ans2))
                {
                    ans2 = s;
                }

                cur.pop_back();
            }
            if (num[i] == '0')
            {
                zero_present = true;
                break;
            }
            cur.push_back(num[i]);
            for (int j = 0; j < 4; j++)
            {
                p[j] -= power_req[num[i] - '0'][j];
                amax(p[j], 0);
            }
        }
        if (!zero_present)
        {
            bool all_zero = true;
            for (int i = 0; i < 4; i++)
            {
                if (p[i])
                    all_zero = false;
            }
            if (all_zero)
                ans2 = cur;
        }
        ans += ans2;
        if (ans.size() == 0 or ans2.size() == 0 or (ans.size() == min_string.size() && min_string < ans))
            ans = min_string;

        if (pos_ans.size() > 0 && (ans.size()>pos_ans.size() or ans.size() == pos_ans.size() && pos_ans < ans))
            ans = pos_ans;

        return ans;
    }
};
