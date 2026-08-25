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

class Group
{
public:
    int k, e;
    unordered_map<int, int> freq;
    Group() : k(0), e(0), freq(unordered_map<int, int>()) {}
    Group(unordered_map<int, int> &freq, int k, int e) : freq(freq), k(k), e(e) {}
    Group(const Group &other) : freq(other.freq), k(other.k), e(other.e) {}

    void insert(int n)
    {
        if (!freq.count(n))
        {
            k++;
            freq[n]++;
        }
        else
        {
            freq[n]++;
            if (freq[n] % 2 == 0)
                e++;
            else
                e--;
        }
    }
    void remove(int n){
        freq[n]--;
        
        if(freq[n] == 0){
            freq.erase(n);
            k--;
        }
        else{
            if(freq[n] % 2 == 0) e++;
            else e--;
        }
    }
};

Group subtract(const Group &g1, Group &g2)
{
    Group ans(g1);
    vi to_erase;
    for (auto &[val, freq] : ans.freq)
    {
        if (freq % 2 == 0)
            ans.e--;
        if (g2.freq.count(val))
            ans.freq[val] -= g2.freq[val];
        if (freq == 0)
        {
            to_erase.push_back(val);
            ans.k--;
        }
        else if (freq % 2 == 0)
            ans.e++;
    }
    for (auto &n : to_erase)
    {
        ans.freq.erase(n);
    }
    return ans;
}

class Solution
{

public:
    vector<bool> validSubarrays(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int group_size = sqrt(n);
        int group_count = (n + group_size - 1) / group_size; // ceil
        vector<vector<Group>> groups(group_count, vector<Group>(group_count));
        Group cur_group;
        for (int i = 0; i < group_count; i++)
        {
            for (int j = 0; j < group_size && i * group_size + j < nums.size(); j++)
            {
                int val = nums[i * group_size + j];
                cur_group.insert(val);
            }
            groups[0][i] = cur_group;
            for (int j = 1; j <= i; j++)
            {
                groups[j][i] = move(subtract(groups[0][i], groups[0][j - 1]));
            }
        }

        vb ans;
        for (auto &q : queries)
        {
            int l = q[0], r = q[1];
            int group_l = l / group_size, group_r = r / group_size;
            Group* cur;
            if (group_r - group_l > 1)
                cur = &groups[group_l + 1][group_r - 1];
            else cur = new Group();
            if (group_l == group_r)
            {
                for (int i = l; i <= r; i++)
                {
                    cur->insert(nums[i]);
                }
            }
            else
            {
                for (int i = l; i / group_size == group_l; i++)
                {
                    cur->insert(nums[i]);
                }
                for (int i = group_r * group_size; i <= r; i++)
                {
                    cur->insert(nums[i]);
                }
            }
            if (cur->k == k && cur->e == k)
                ans.push_back(true);
            else
                ans.push_back(false);

            if (group_l == group_r)
            {
                for (int i = l; i <= r; i++)
                {
                    cur->remove(nums[i]);
                }
            }
            else
            {
                for (int i = l; i / group_size == group_l; i++)
                {
                    cur->remove(nums[i]);
                }
                for (int i = group_r * group_size; i <= r; i++)
                {
                    cur->remove(nums[i]);
                }
            }
        }
        return ans;
    }
};
