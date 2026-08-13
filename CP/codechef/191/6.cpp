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
#define endl "\n"
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

void make_prefix_sum(vll& arr, int n){
    rep1(i, n-1){
        arr[i] += arr[i-1];
    }
}

vll get_cost1(string& s1, int n){
    vll cost1;
    int zeros = 0;
    rep(i, n){
        if(s1[i] == '0') zeros++;
        else cost1.push_back(zeros);
    }

    make_prefix_sum(cost1, cost1.size());
    return cost1;
}

vll get_cost2(string& s2, int n){
    vll cost2;
    int zeros = 0;
    rev(i, n, 1){
        if(s2[i] == '0') zeros++;
        else cost2.push_back(zeros);
    }
    
    make_prefix_sum(cost2, cost2.size());
    return cost2;
}

ll get_cost_for_one_index(vll& cost1, vll& cost2, int i, int n){
    if(cost1.size()>=(i+1) && cost2.size()>=(n-i)){
        return cost1[i] + cost2[n-i-1];
    }
    return INT64_MAX;
}

void build(vll& segment_tree, int left, int right, vll& cost1, vll& cost2, int n, int index = 0){
    if(left == right){
        segment_tree[index] = get_cost_for_one_index(cost1, cost2, left, n);
        return;
    }
    int mid = (left+right)/2;
    int left_child =  index*2 + 1, right_child = index*2 + 2;
    build(segment_tree, left, mid, cost1, cost2, n, left_child);
    build(segment_tree, mid+1, right, cost1, cost2, n, right_child);
    segment_tree[index] = min(segment_tree[left_child], segment_tree[right_child]);
}

void solve(string& s1, string& s2, int n, vector<pii>& queries, int q){
    vll cost1 = get_cost1(s1, n);
    vll cost2 = get_cost2(s2, n);
    
    

    vll segment_tree(4*n);
    build(segment_tree, 0, n-1, cost1, cost2, n);
    cout<<(segment_tree[0] == INT64_MAX? -1: segment_tree[0])<<endl;
    
    rep(i, q){
        
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, q; in >> n>>q;
        string s1, s2;
        in>>s1>>s2;
        vector<pii> queries(q);
        rep(i, q){
            int x, y;
            in>>x>>y;
            queries[i] = {x, y};
        }
        // Your logic here
        solve(s1, s2, n, queries, q);
    }
    return 0;
}