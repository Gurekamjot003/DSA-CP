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

// vi primes = prime_numbers_upto(5e4+1);

int sum_of_n(int n){
    return n*(n+1)/2;
}

class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        vi last_2_primes;
        map<int, int> freq;
        int ans = 0;
        int n = nums.size();
        int min_prime = INT_MAX, max_prime = INT_MIN;
        int left = 0;
        rep(right, n){
            if(is_prime(nums[right])){
                freq[nums[right]]++;
                last_2_primes.push_back(right);
                if(last_2_primes.size()>2)last_2_primes.erase(last_2_primes.begin());
                amax(max_prime, nums[right]);
                amin(min_prime, nums[right]);
            }

            if(last_2_primes.size()==2){
                while(max_prime - min_prime > k){
                    if(is_prime(nums[left])){
                        freq[nums[left]]--;
                        if(freq[nums[left]] == 0) freq.erase(nums[left]);
                    }
                    left++;
                    auto it = freq.rbegin();
                    max_prime = it->first;
                    
                    auto it2 = freq.begin();
                    min_prime = it2->first;
                }
                if((nums[last_2_primes[1]] - nums[last_2_primes[0]]) > k){
                    last_2_primes.erase(last_2_primes.begin());
                }
            }
            if(last_2_primes.size() == 2){
                ans += last_2_primes[0] - left + 1;
            }            
        }
        return ans;
    }
};