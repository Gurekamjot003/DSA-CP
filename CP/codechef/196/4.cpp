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

class BIT{
    int n;
    vector<int> bit_a;
    vector<int> bit_b;
    vector<int> bit_diff;
    int k;
    
    void update_bit(vi& bit, int val, int id){
        while(id<=n){
            bit[id] += val;
            id += (id & -id);
        }
    }

    int prefix_sum(vi& bit, int id){
        int ans = 0;
        while(id>0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
public:
    BIT(vector<int>& a, vi& b, int k): k(k){
        n = a.size() -1;
        bit_a.resize(n+1);
        bit_b.resize(n+1);
        bit_diff.resize(n+1);
        for(int i = 1; i<=n; i++){
            update(i, a[i],0, false);
            update(i, b[i], 1, false);
            if(abs(a[i] - b[i]) > k) update_bit(bit_diff, 1, i);
        }
    }


    void update(int id, int val, bool array, bool user_update = true){
        vi& bit = (array? bit_b: bit_a);
        int old_flag;
        if(user_update){
            int a_id = prefix_sum(bit_a, id) - prefix_sum(bit_a, id-1),
                b_id = prefix_sum(bit_b, id) - prefix_sum(bit_b, id-1);
            old_flag = abs(a_id - b_id) > k;
        }
        update_bit(bit, val, id);

        if(user_update){
            int a_id = prefix_sum(bit_a, id) - prefix_sum(bit_a, id-1),
                b_id = prefix_sum(bit_b, id) - prefix_sum(bit_b, id-1);
            int new_flag = abs(a_id - b_id) > k;

            int diff = new_flag - old_flag;
            update_bit(bit_diff, diff, id);
        }
    }

    int sum_query(int id, bool array){
        vi& bit = (array? bit_b: bit_a);
        return prefix_sum(bit, id);
    }

    int left_most_fixed_value(int id){
        vi& bit = bit_diff;
        int cur = prefix_sum(bit, id);
        int ans = n+1;

        int left = id+1, right=n;
        while(left<=right){
            int mid = (left+right)/2;
            if(prefix_sum(bit_diff, mid) > cur){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans-1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        
        // cout << result << endl;
    }
    return 0;
}