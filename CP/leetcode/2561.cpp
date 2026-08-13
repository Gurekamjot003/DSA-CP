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
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep1(i, n) for(int i = 1; i<=n; i++)
#define rev(i, n, step) for(int i = n-1; i>=0; i-= step)

template<typename T>
void amin(T& a, T b){ a = min(a, b); }
template<typename T>
void amax(T& a, T b){ a = max(a, b); }

template<typename T>
T gcd(T a, T b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        T t = b;
        b = a % b;
        a = t;
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

vector<int> prime_numbers_upto(int n){
    vector<bool> is_prime(n+1, true);
    vi ans;
    for(int i = 2; i<=n; i++){
        if(!is_prime[i]) continue;
        ans.push_back(i);
        for(int j = i*2; j<=n; j+=i) is_prime[j] = false;
    }
    return ans;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}
#endif

vector<pair<ll, ll>> get_freq_diff_arr(vi& basket1, vi& basket2){
    unordered_map<int,int> freq;
        for(auto& n: basket1) freq[n]++;
        for(auto& n: basket2) freq[n]--;
        // for(auto& it: freq) cout<<it.first<<" "<<it.second<<endl;
        vi to_delete;
        for(auto& it: freq){
            if(it.second %2) return {{-1, -1}};
            it.second/=2;
        }
        
        vector<pair<ll, ll>> freq_arr;
        for(auto& it: freq){
            if(it.second) freq_arr.push_back({it.first, abs(it.second)});
        }
        if(freq_arr.empty()) return freq_arr;
        sort(all(freq_arr));

        return freq_arr;
}

ll get_min_ele(vi& basket1, vi& basket2){
    ll min_val = *min_element(all(basket1));
    amin(min_val, 0ll + *min_element(all(basket2)));
    min_val*=2;
    return min_val;
}


class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        vector<pair<ll,ll>> freq_arr = get_freq_diff_arr(basket1, basket2);
        if(freq_arr.empty()) return 0;
        if(freq_arr.begin()->first == -1) return -1;

        ll ans= 0;
        int left = 0, right=freq_arr.size()-1;
        ll min_val = get_min_ele(basket1, basket2);
        while(left<right){
            auto& [smaller_val, smaller_freq] = freq_arr[left];
            auto& [greater_val, greater_freq] = freq_arr[right];
            int min_freq = min(smaller_freq, greater_freq);
            ans += min(smaller_val, min_val) * min_freq;
            smaller_freq -= min_freq;
            greater_freq -= min_freq;
            if(smaller_freq == 0){
                left++;
            }
            if(greater_freq == 0){
                right--;
            }
        }
        if(left == right){
            auto& [val, freq] = freq_arr[left];
            if(freq%2) return -1;
            ans += min(val, min_val)*(freq/2);
        }
        
        return ans;
    }
};