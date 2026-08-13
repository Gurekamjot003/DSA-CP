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

vi unpleasant_strings(int k, string& pattern, int q){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();

    int n = pattern.size();
    
    vvi last_occ(n);
    vi cur_last_occ(k, n);
    vi steps_req(n+1);
    for(int i = n-1; i>=0; i--){
        int ch = pattern[i]-'a';
        int farthest = *max_element(all(cur_last_occ));
        steps_req[i] = 1 + steps_req[farthest];
        last_occ[i] = cur_last_occ;
        cur_last_occ[ch] = i;
    }
    vi ans;
    for(int j = 0; j<q; j++){
        string query;
        in>>query;
        int ptr = cur_last_occ[query[0]-'a'];
        int i = 1;
        for(; i<query.size(); i++){
            if(ptr>=n){
                break;
            }
            ptr = last_occ[ptr][query[i]-'a'];
        }
        if(ptr>=n){
            // if(i == (query.size())) ans.push_back(1);
            ans.push_back(0);
            continue;
        }

        ans.push_back(steps_req[ptr]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int n, k;
    in>>n>>k;
    string s; in>>s;
    int q; in>>q;
    vi ans = unpleasant_strings(k, s, q);
    for(auto& n: ans) cout<<n<<endl;

    return 0;
}