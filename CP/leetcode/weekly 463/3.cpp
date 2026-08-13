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

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0;
        rep1(i, n-1) sum += nums[i];
        cout<<sum<<" "<<sum%34<<endl;
        vi new_nums;
        ll window_sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            
            window_sum += nums[i] % k;
            window_sum %= k;

            if(window_sum == 0){
                mp.clear();
                new_nums = {};
                continue;
            }

            if(mp.find(window_sum) != mp.end()){
                int idx = mp[window_sum];
                window_sum -= nums[i];
                window_sum = (window_sum + (ll)ceil((0.0 - window_sum)/k) * k)%k;

                while(idx < (new_nums.size()-1)){
                    mp.erase(window_sum);
                    window_sum -= new_nums.back();
                    new_nums.pop_back();
                    window_sum = (window_sum + (ll)ceil((0.0 - window_sum)/k) * k)%k;
                }
                continue;
            }

            new_nums.push_back(nums[i]);
            mp[window_sum] = new_nums.size()-1;
        }
        return accumulate(all(new_nums), 0ll);
    }
};

int main(){
    Solution sol;
    vi nums = {58,68,57,71,52,6,40,22,13,29,26,17,47,31,51,73,59,69,37,14};
    cout<<sol.minArraySum(nums, 34);
}