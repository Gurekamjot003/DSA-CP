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

    class Median_find{
        priority_queue<pii> smaller;
        priority_queue<pii, vector<pii>, greater<>> greater;
        int greater_count, smaller_count;
        ll smaller_sum, greater_sum;
        int x; // size of subarray
        void lazy_pop(int i){
            while(!smaller.empty() && smaller.top().second <= i-x){
                smaller.pop();
            }
            while(!greater.empty() && greater.top().second <= i-x){
                greater.pop();
            }
        }
        void rebalance(int i){ // this makes sure that greater_count is equal to smaller_count or smaller_count+1
            lazy_pop(i);
            while(smaller_count != greater_count && smaller_count+1 != greater_count){
                if(!greater.empty() && smaller_count < greater_count){
                    smaller.push(greater.top());
                    smaller_sum += greater.top().first;
                    greater_sum -= greater.top().first;
                    greater.pop();
                    smaller_count++;
                    greater_count--;
                }
                else if(!smaller.empty()){
                    greater.push(smaller.top());
                    greater_sum += smaller.top().first;
                    smaller_sum -= smaller.top().first;
                    smaller.pop();
                    greater_count++;
                    smaller_count--;
                }
                lazy_pop(i);
            }
        }

        void remove(int val){ // index to be removed
            if(!smaller.empty() && val <= smaller.top().first){
                smaller_sum -= val;
                smaller_count--;
            }
            else if(!greater.empty() && val >= greater.top().first){
                greater_sum-= val;
                greater_count--;
            }
        }
        public:

            Median_find(int x): x(x){
                smaller = priority_queue<pii>();
                greater = priority_queue<pii, vector<pii>, ::greater<>>();
                greater_count = smaller_count = smaller_sum = greater_sum = 0;
            }

            void insert(vi& nums, int i){
                if(i-x>=0){
                    remove(nums[i-x]);
                }
                rebalance(i);
                if(greater.size() == 0 or nums[i]>=greater.top().first){
                    greater.push({nums[i], i});
                    greater_sum += nums[i];
                    greater_count++;
                }
                else{
                    smaller.push({nums[i], i});
                    smaller_sum += nums[i];
                    smaller_count++;
                }
                rebalance(i);
            }

            int get_median(){
                if(greater_count == smaller_count+1) return greater.top().first;
                return (greater.top().first + smaller.top().first)/2;
            }

            ll get_cost(){
                ll median = get_median();
                return median*smaller_count-smaller_sum + greater_sum-greater_count*median;
            }
    };

    vll get_cost_arr(vi& nums, int x){
        Median_find med(x);
        vll ans;
        rep(i, nums.size()){
            med.insert(nums, i);
            if(i>=x-1){
                ans.push_back(med.get_cost());
            }
        }
        return ans;
    }
    #define vvll vector<vll>

    ll solve(vvll& dp, vll& cost_arr, int k, int n, int x, int i = 0, int cur_k = 0){
        if(cur_k == k) return 0;
        if(i >= n) return INT64_MAX/10;

        if(dp[i][cur_k] != INT64_MIN) return dp[i][cur_k];

        ll pick = cost_arr[i] + solve(dp, cost_arr, k, n, x, i+x, cur_k+1);
        ll skip = solve(dp, cost_arr, k, n, x, i+1, cur_k);
        return dp[i][cur_k] = min(pick, skip);
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vll cost_arr = get_cost_arr(nums, x);
      
        int n = cost_arr.size();
        vvll dp(n, vll(k+1, INT64_MIN));
        
        return solve(dp, cost_arr, k, n, x);
    }
};