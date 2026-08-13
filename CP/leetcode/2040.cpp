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

void count_pairs_less_equal(ll target, vi& nums1, vi& nums2, ll& total_nums){
    for(int nums1_ptr = 0; nums1_ptr<nums1.size(); nums1_ptr++){
        int cur_nums = 0;
        int left = 0, right= nums2.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            ll product = nums1[nums1_ptr];
            product *= 1ll*nums2[mid];
            if(product>target){
                right = mid-1;
            }
            else{
                cur_nums = mid+1;
                left = mid+1;
            }
        }
        total_nums += cur_nums;
    }
}

bool has_at_least_k_pairs(ll target, vi& nums1, vi& nums2, vi& neg_nums1, vi& neg_nums2, vi& neg_nums2_rev, ll k){
    ll total_nums = 0;
    count_pairs_less_equal(target, nums1, nums2, total_nums);
    count_pairs_less_equal(target, nums1, neg_nums2, total_nums);
    count_pairs_less_equal(target, nums2, neg_nums1, total_nums);
    count_pairs_less_equal(target, neg_nums1, neg_nums2_rev, total_nums);
    return total_nums>=k;
}

vi get_negative_nums(vi& nums){
    vi neg_nums;
    int ptr = 0;
    rep(i, nums.size()){
        if(nums[i]>=0){
            nums[ptr++] = nums[i];
        }
        else neg_nums.push_back(nums[i]);
    }
    while(nums.size()>ptr) nums.pop_back();
    return neg_nums;
}

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vi neg_nums1 = get_negative_nums(nums1);
        vi neg_nums2 = get_negative_nums(nums2);
        vi neg_nums2_rev = neg_nums2;
        reverse(all(neg_nums2_rev));
        
        ll left = -1e10, right = 1e10;
        ll ans = right;
        while(left<=right){
            ll mid = (left+right)/2;
            if(has_at_least_k_pairs(mid, nums1, nums2, neg_nums1, neg_nums2, neg_nums2_rev, k)){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
            
        }
        return ans;
    }
};
