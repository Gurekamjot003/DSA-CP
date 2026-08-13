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

#define pipii pair<int, pii>

const int mod = 1e9 + 7;

class Solution
{
    int n;

    ll ap_sum(ll n, ll first, ll d)
    {
        ll ans = 0;
        ans = n * (2 * first + (n - 1) * d) / 2;
        return ans%mod;
    }

    pair<int, ll> get_count_sum(int min_val, vector<pii> &val_decay, int m)
    {
        ll cur = 0;
        priority_queue<pii> pq;
        rep(i, n)
        {
            auto [value, decay] = val_decay[i];
            if (value < min_val)
            {
                continue;
            }
            int decay_count = max<int>(0, (0ll + value - min_val) / decay);
            ll first = 0ll + value - 1ll * decay * decay_count;
            ll sum = ap_sum(decay_count + 1, first, decay);
            cur = (cur+sum)%mod;
            m -= decay_count+1;
            if(m<0) break;
        }

        return {m,cur};
    }

    pair<int, vi> tester(vector<pii> &val_decay, int m)
    {
        priority_queue<pii> pq;
        for (int i = 0; i < n; i++)
        {
            auto &[value, decay] = val_decay[i];
            pq.push({value, i});
        }
        vi freq(n);
        ll sum = 0;
        while (m > 0 && !pq.empty())
        {
            auto [value, i] = pq.top();
            int decay = val_decay[i].second;
            pq.pop();
            if (value < 0)
                break;
            sum = (sum + value) % mod;
            freq[i]++;
            m--;
            pq.push({value - decay, i});
        }
        return {sum, freq};
    }

public:
    int maxTotalValue(vector<int> &value, vector<int> &decay, int m)
    {
        n = value.size();
        vector<pii> val_decay(n);
        ll max_ele_pos = 0;
        rep(i, n)
        {
            val_decay[i] = {value[i], decay[i]};
            max_ele_pos += (0ll + value[i]) / decay[i] + 1;
        }
        if (max_ele_pos < m)
            m = max_ele_pos;

        // auto [sum, freq] = tester(val_decay, m);
        // cout << sum << endl;
        // for (auto &n : freq)
        //     cout << n << " ";
        // cout << endl;
        int left = 1, right = *max_element(all(value)) + 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            auto [count,sum] = get_count_sum(mid, val_decay, m);
            if (count>=0 && count <=n){
                priority_queue<pii> pq;
                for(auto[value, decay]: val_decay){
                    if(value<mid){
                        pq.push({value, decay});
                        continue;
                    }
                    int decay_count = max(0,(value - mid)/decay);
                    int first = value-decay*decay_count;
                    if(first-decay>0) pq.push({first-decay, decay});
                }
                while(!pq.empty() && count-- > 0){
                    auto[value, decay] = pq.top();
                    pq.pop();
                    sum = (sum+value)%mod;
                    if(value-decay>0) pq.push({value-decay, decay});
                }
                return sum;
            }
            if(count>n){
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return right-1;
    }
};

// int main()
// {
//     Solution sol;
//     vi value = {7,1,9,8};
//     vi decay = {10,3,1,3};
//     cout << sol.maxTotalValue(value, decay, 6);
// }