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
    int k, x;
    ll sum;
    umapii max_freq, min_freq;
    priority_queue<pii> max_heap;
    priority_queue<pii, vector<pii>, greater<>> min_heap;

    void init(vector<int>& nums, int k, int x){
        n = nums.size();
        this->k = k;
        this->x = x;
        sum = 0;
        max_freq.clear();
        min_freq.clear();
        while(!max_heap.empty()) max_heap.pop();
        while(!min_heap.empty()) min_heap.pop();
    }

    void change_freq_in_min(int ele, int dfreq){
        min_freq[ele] += dfreq;
        min_heap.push({min_freq[ele], ele});
    }

    void change_freq_in_max(int ele, int dfreq){
        max_freq[ele] += dfreq;
        max_heap.push({max_freq[ele], ele});
    }

    void add_ele_to_window(int ele){
        // element already in sum
        if(min_freq.count(ele) or min_freq.size()<x){
            change_freq_in_min(ele, 1);
            sum += ele;
        }
        else{ // element not in sum
            change_freq_in_max(ele, 1);
        }
    }
    
    void remove_ele_from_window(int ele){
        // element already in sum
        if(min_freq.count(ele)){
            change_freq_in_min(ele, -1);
            sum -= ele;
        }
        else{ // element not in sum
            change_freq_in_max(ele, -1);
        }
    }

    pii get_max_top(){
        // remove inconsistency
        while(!max_heap.empty()){
            auto [cur_max_freq, cur_max] = max_heap.top();
            if(max_freq.count(cur_max) && max_freq[cur_max] == cur_max_freq) return max_heap.top();
            max_heap.pop();
        }
        return {0, 0};
    }
    
    pii get_min_top(){
        // remove inconsistency
        while(!min_heap.empty()){
            auto [cur_min_freq, cur_min] = min_heap.top();
            if(min_freq.count(cur_min) && min_freq[cur_min] == cur_min_freq) return min_heap.top();
            min_heap.pop();
        }
        return {0, 0};
    }

    void process_window_and_remove_incons(){
        while(true){
            auto [cur_max_freq, cur_max] = get_max_top();
            auto [cur_min_freq, cur_min] = get_min_top();
            
            if(!max_heap.empty() && !min_heap.empty() && (cur_max_freq>cur_min_freq or (cur_max_freq==cur_min_freq && cur_max>cur_min))){
                // swap min & max
                max_heap.pop();
                min_heap.pop();
                max_freq.erase(cur_max);
                min_freq.erase(cur_min);
                max_heap.push({cur_min_freq, cur_min});
                min_heap.push({cur_max_freq, cur_max});
                max_freq[cur_min] = cur_min_freq;
                min_freq[cur_max] = cur_max_freq;
                sum -= 1ll*cur_min*cur_min_freq;
                sum += 1ll*cur_max*cur_max_freq;
            }
            else return;
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        init(nums, k, x);
        vll ans(n - k +1);
        for(int i = 0; i<n; i++){
            // add ith element to window
            add_ele_to_window(nums[i]);

            // remove i-kth element from window
            if(i>=k) remove_ele_from_window(nums[i-k]);

            // process window and fix heaps
            process_window_and_remove_incons();

            // add sum to answer
            if(i>=k-1) ans[i-k+1] = sum;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vi nums = {4,5,3,5,2,3,6,6,5,4};
    vll ans = sol.findXSum(nums, 4, 2);
    for(auto& n: ans) cout<<n<<" ";
}