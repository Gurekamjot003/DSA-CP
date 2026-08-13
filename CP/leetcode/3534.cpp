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

    int find_greater(vi& nums, int i, int max_diff, int end){
        int left = i+1, right =end;
        int ans = i+1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]-nums[i]<=max_diff){
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }

    int find_exact(vi& nums, int val){
        int left = 0, right= nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == val) return mid;
            if(nums[mid]>val) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
    void fill(vvi& parent, int n, vi& nums, int start, int end, int max_diff){
        for(int i = end-1; i>=start; i--){
            int j = find_greater(nums, i, max_diff, end); // find using bs
            parent[i][0] = j;
            int p = 0;
            
            while(j<=end && parent[j][p] != -1){
                j = parent[j][p++];
                parent[i][p] = j;
            }
        }
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vi sorted_nums = nums;
        sort(all(sorted_nums));
        int max_ele = *max_element(all(nums));
        vi temp = {sorted_nums[0]};
        for(int i = 1; i<n; i++){
            if(sorted_nums[i] != sorted_nums[i-1]) temp.push_back(sorted_nums[i]);
        }
        sorted_nums = move(temp);
        n = sorted_nums.size();
        sorted_nums.push_back(INT_MAX);
        int ln = log2(max(1, n)) + 1;
        vvi parent(n+1, vi(ln, -1));
        int start = 0;
        for(int i = 1; i<=n; i++){
            if(sorted_nums[i] - sorted_nums[i-1] > maxDiff){
                int end = i-1;
                fill(parent, n, sorted_nums, start, end, maxDiff);
                start = i;
            }
        }

        vi ans;
        for(auto& q: queries){
            int u = q[0], v = q[1];
            if(nums[u] == nums[v]){
                ans.push_back((u == v? 0: 1));
                continue;
            }
            if(nums[u]>nums[v]) swap(u, v);
            int cur = 0, i = find_exact(sorted_nums, nums[u]);
           
                
            for(int p = ln-1; p>=0; p--){
                if(parent[i][p] == -1 or sorted_nums[parent[i][p]] > nums[v]) continue;
                i = parent[i][p];
                cur += 1<<p;
            }
            if(sorted_nums[i] == nums[v]) ans.push_back(cur);
            else if(nums[v] - sorted_nums[i] <= maxDiff) ans.push_back(cur+1);
            else ans.push_back(-1);
        }

        
        return ans;
    }
};