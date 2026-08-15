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

template<class T>
class SegmentTree{
    vector<T> tree;
    vector<T> data;

    T init(int index){
        return data[index];
    }

    T combine(T val_1, T val_2){
        return val_1 + val_2;
    }

    void update_helper(int target_index, int left, int right, int index = 0){
        if(left == right){
            tree[index] = init(target_index);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        if(target_index<=mid) update_helper(target_index, left, mid, left_child);
        else update_helper(target_index, mid+1, right, right_child);

        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    T query_helper(int q_left, int q_right, int left, int right, int index = 0){
        if(left>=q_left && right<=q_right) return tree[index];
        if(left>q_right or right<q_left) return (T)0;
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid+1, right, right_child)); 
    }

public:
    SegmentTree(vector<T>& data){
        int sz = data.size();
        tree.resize(sz*4);
        this->data = data;
        int left = 0, right= data.size()-1;
        build(data, left, right);
    }

    void build(vector<T>& data, int left, int right, int index = 0){
        if(left == right){
            tree[index] = init(left);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        build(data, left, mid, left_child);
        build(data, mid + 1, right, right_child);
        
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    void update(int data_index, T value){
        data[data_index] = value;
        update_helper(data_index, 0, data.size()-1);
    }

    T get_value(int q_left, int q_right){
        return query_helper(q_left, q_right, 0, data.size()-1);
    }

};

class Solution {
    void add(SegmentTree<ll>& l2_sum, SegmentTree<ll>&l_adj_sum, ll i, set<ll>& l_vals_st,SegmentTree<ll>& l_sum){
        if(l_vals_st.count(i)) return; // already present
        l2_sum.update(i, i*i);
        ll left = val_at_target_in_st(l_vals_st, i); // it will always give value at left as there is no peak at i
        l_sum.update(i, i-left);
        l_adj_sum.update(i, left*i);
        // update value for right 
        ll right = val_after_target_in_st(l_vals_st, i);
        if(right != -1){
            l_sum.update(right, right-i);
            l_adj_sum.update(right, right*i);
        }
        l_vals_st.insert(i);
    }
    void remove(SegmentTree<ll>&l2_sum, SegmentTree<ll>& l_adj_sum, ll i, set<ll>&l_vals_st,SegmentTree<ll>& l_sum){
        if(!l_vals_st.count(i)) return;
        l2_sum.update(i, 0);
        l_adj_sum.update(i, 0);
        l_sum.update(i, 0);
        l_vals_st.erase(i);
        ll left = val_at_target_in_st(l_vals_st, i), right = val_after_target_in_st(l_vals_st, i);
        // old value will be right * i, new will be right * left
        if(right != -1){
            l_sum.update(right, right-left);
            l_adj_sum.update(right, right*left);
        }
    }
    ll val_at_target_in_st(set<ll>& st, ll target){
        auto it = st.upper_bound(target);
        it--;
        return *it;
    }
    ll val_after_target_in_st(set<ll>& st, ll target){
        auto it = st.upper_bound(target);
        if(it == st.end()) return -1;
        return *it;
    }
    
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vll ans;
        ll n = nums.size();
        vll l_vals(n), l2_sum_arr(n), l_adj_sum_arr(n);
        SegmentTree l2_sum(l2_sum_arr), l_adj_sum(l_adj_sum_arr), l_sum(l_vals);
        set<ll> l_vals_st;
        l_vals_st.insert(0);
        
        rep1(i, n-2){
            if(nums[i]>nums[i+1] && nums[i] > nums[i-1]){
                add(l2_sum, l_adj_sum, i, l_vals_st, l_sum);
            }
        }
        int i = 0;
        for(auto&q: queries){
            if(q[0] == 1){
                ll l = q[1], r = q[2];
                ll size = r-l+1;
                ll cur = 0;
                ll l1 = val_after_target_in_st(l_vals_st, l); // we want current or greater
                if(l1 == -1){
                    ans.push_back(cur);
                    continue;
                }
                
                cur = max(0ll, (l1-l)*(size-1-(l1-l)));
                l = l1;
                size = r-l+1;
                
                ll t1 = l_sum.get_value(l+1, r-1)*(size-1+l), t2 = l2_sum.get_value(l+1, r-1), t3 = l_adj_sum.get_value(l+2,r-1);
                cur += max(0ll,t1-t2+t3);
                ans.push_back(cur);
                
            }
            else{
                ll i = q[1], val = q[2];
                
                nums[i] = val;
                for(ll j = max(1ll, i-1); j<=min(n-2, i+1); j++){
                    remove(l2_sum, l_adj_sum, j, l_vals_st, l_sum);
                    if(nums[j-1]<nums[j] && nums[j+1]<nums[j]){
                        add(l2_sum, l_adj_sum, j, l_vals_st, l_sum);
                    }
                }
            }
            i++;
        }
        
        return ans;

    }
};