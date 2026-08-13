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

class Trie
{
public:
    map<string, Trie *> next;
    string folder_name;
    string subfolders;

    Trie(string folder_name) : folder_name(folder_name), subfolders("")
    {
    }

    void insert(vector<string> &path)
    {
        Trie *node = this;
        for (auto &folder_name : path)
        {
            if (!node->next[folder_name])
                node->next[folder_name] = new Trie(folder_name);
            node = node->next[folder_name];
        }
    }

    static string fill_freq(Trie *node, map<string, int> &freq)
    {
        vector<string> subfolders;
        for (auto &it : node->next)
        {
            if (it.second)
                subfolders.push_back(fill_freq(it.second, freq));
        }
        sort(all(subfolders));
        string cur;
        for (auto &s : subfolders)
            cur += s;
        node->subfolders = cur;
        if(cur != "") freq[cur]++;
        cur = node->folder_name + cur;
        return "("+cur+")";
    }

    static void delete_duplicates(Trie *node, map<string, int> &freq)
    {
        vector<string> keys_to_delete;
        for (auto &it : node->next)
        {
            if (it.second && freq[it.second->subfolders] > 1)
            {
                keys_to_delete.push_back(it.first);
            }
            else if (it.second)
            {
                delete_duplicates(it.second, freq);
            }
        }
        for (auto &key : keys_to_delete)
        {
            node->next.erase(key);
        }
    }

    static void fill_ans(Trie *node, vector<string> &cur, vector<vector<string>> &ans)
    {
        cur.push_back(node->folder_name);
        ans.push_back(cur);
        for (auto &it : node->next)
        {
            if (it.second)
            {
                fill_ans(it.second, cur, ans);
            }
        }
        cur.pop_back();
    }
};

class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        int n = paths.size();
        Trie *root = new Trie("/");
        for (auto &path : paths)
        {
            root->insert(path);
        }

        map<string, int> freq;
        Trie::fill_freq(root, freq);

       

        Trie::delete_duplicates(root, freq);

        vector<vector<string>> ans;
        vector<string> cur;
        for (auto &it : root->next)
        {
            if (it.second)
                Trie::fill_ans(it.second, cur, ans);
        }
        return ans;
    }
};