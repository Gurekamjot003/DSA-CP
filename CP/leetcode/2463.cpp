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
#define vvll vector<vll>
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
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<>> minheap;
        int N = nums.size(), n = N/3;
        vvll dp(2, vll(N));
        rep(i, N){
            dp[0][i] = INT64_MAX/10;
            dp[1][i] = INT64_MIN/10;
        }
        ll sum = 0;
        rep(i, N){
            pq.push(nums[i]);
            sum += nums[i];
            if(pq.size()>n){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == n) amin(dp[0][i], sum);
        }
        sum = 0;
        for(int i = N-1; i>=0; i--){
            minheap.push(nums[i]);
            sum += nums[i];
            if(minheap.size()>n){
                sum -= minheap.top();
                minheap.pop();
            }
            if(minheap.size() == n) amax(dp[1][i], sum);
        }
        
        ll ans = INT64_MAX;
        for(int i = n-1; i<2*n; i++){
            amin(ans, dp[0][i]-dp[1][i+1]);
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    vi nums = {7,9,5,8,1,3};
    cout<<sol.minimumDifference(nums);
}