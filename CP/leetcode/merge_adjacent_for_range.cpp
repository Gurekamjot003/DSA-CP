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
    int n;
    vector<pii> range;
    vi parent;

    int find_ulti_parent(int i){
        if(parent[i] == i) return i;
        return parent[i] = find_ulti_parent(parent[i]);
    }

    void init(vi& nums){
        n = nums.size();
        range = vector<pii>(n);
        rep(i, n) range[i] = {nums[i], nums[i]};
        parent = vi(n);
        iota(all(parent), 0);
    }

    bool merge_possible(int left, int right, int limit){
        auto[s1,f1] = range[left];
        auto[s2,f2] = range[right];

        s2-=limit; f2+=limit;

        if((s2<=f1 && f2>=f1) or (s2<=s1 && f2>=s1)) return true;
        return false;
    }
    void merge(int left, int right){
        parent[right] = left;
        amin(range[left].first, range[right].first);
        amax(range[left].second, range[right].second);
    }

public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        init(nums);

        rep1(i, n-1){
            int cur = i;
            while(cur>0){
                
                int right = find_ulti_parent(cur); int left = find_ulti_parent(right-1);
                if(merge_possible(left, right, limit)){
                    merge(left, right);
                    cur = left;
                }
                else break;
            }
        }
        for(int i = n-1; i>=0; i--){
            parent[i] = find_ulti_parent(i);
        }
        
        parent.push_back(n);

        int prev = 0;
        rep1(i, n){
            if(parent[i] != parent[i-1]){
                sort(nums.begin()+prev, nums.begin()+i);
                prev = i;
            }
        }
        return nums;
    }
};