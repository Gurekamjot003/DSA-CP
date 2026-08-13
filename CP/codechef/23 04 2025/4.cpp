#include <bits/stdc++.h>
using namespace std;

// Macros
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
#define v vector
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
#define endl "\n"

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

// Function to get input stream based on file availability
istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}

ll complete_graph_edges_count(ll n){
    return 1ll*n*(n-1ll)/2ll;
}

ll sum(int n){
    return n*(n+1ll)/2;
}

ll final(ll start, ll end){
    return sum(end) - sum(start-1);
}

ll complete_mst(int n, ll m){
    ll total_edges = complete_graph_edges_count(n);
    ll num_edges_with_0_wt = total_edges - m;
    ll num_edges_with_1_wt = m;
    if(num_edges_with_0_wt <=2) return n - 1 - num_edges_with_0_wt;
    int left = 0, right = min(num_edges_with_0_wt, n-1ll);
    int val = right;
    while(left<=right){
        int mid = (left+right)/2;
        ll possible_zeros_used = complete_graph_edges_count(mid);
        if(possible_zeros_used >= num_edges_with_0_wt){
            val = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    // cout<<val<<endl;
    ll to_calc = n- val;
    // ll ans = (to_calc*(to_calc+1ll))/2ll;
    ll min_ans = max(0ll, n - 1ll-num_edges_with_0_wt);
    return final(min_ans, to_calc);
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        ll m; in>>m;

        // Your function call here
        cout << complete_mst(n, m) << endl;
        // cout<<"-------------------------------------"<<endl;
    }

    return 0;
}