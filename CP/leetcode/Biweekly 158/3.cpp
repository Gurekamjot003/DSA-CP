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
// #define endl "\n"
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


class Solution {
    int get_power_2(int n){
        int ans = 0;
        while(n%2 == 0){
            ans++;
            n/=2;
        }
        return ans;
    }
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        vi power_2(n);
        rep(i, n){
            power_2[i] = get_power_2(nums[i]);
        }

        rep(i, n){
            int min_power_2 = 31, count = 0;
            int cur_gcd = nums[i];
            for(int j = i; j<n; j++){
                int cur_power_2 = power_2[j];
                if(cur_power_2 < min_power_2){
                    min_power_2 = cur_power_2;
                    count = 1;
                }
                else if(cur_power_2 == min_power_2) count++;
                int total_count = j-i+1; // length of subarray
                cur_gcd = gcd(cur_gcd, nums[j]);
                if(count<=k) amax(ans, 1ll*total_count*cur_gcd*2);
                else amax(ans, 1ll*total_count*cur_gcd);
            }
        }
        return ans;
    }
};
