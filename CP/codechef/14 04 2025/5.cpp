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

v<string> strings;

void precompute_string(){
    int sz = 22;
    strings.push_back("01");
    string cur = "1";
    for(int i = 1; i<sz; i++){
        cur += cur;
        strings.push_back(cur);
    }
}

string segment_tree_reconstruction(int n, int k){
    string ans;
    int sz = (1<<n);
    int prev = -1;
    for(int i = strings.size()-1; i>=0 && (ans.size()<(i<<n)); i--){
        
        if((((1<<(i+1))-1) <= k) && ((ans.size() + strings[i].size())<=sz)){    //2^(i+1) - 1
            if(i!= 0 && prev == i){
                k -= (1<<(i)-1);
                ans += strings[i-1];
                prev = i-1;
                continue;
            }
            k-= ((1<<(i+1))-1);
            ans+=strings[i];
            prev = i;
        }
    }
    // cout<<ans<<endl;
    // cout<<k<<endl;
    
    while(ans.size()<(1<<n)) ans.push_back('0');
    for(int i = 0; i<ans.size() && k>0; i+=2){
        if(ans[i] == '0' && ans[i+1] == '0'){
            ans[i] = '1';
            k--;
        }
    }
    // cout<<ans<<endl;
    
    if((ans.size()>(1<<n)) or k!= 0) return "";
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    precompute_string();
    int t; in >> t;
    while (t--) {
        int n, k; in >> n>>k;
        
        // Your function call here
        string ans = segment_tree_reconstruction(n, k);
        yn(ans.size());
        if(ans.size()) cout<<ans<<endl;
        // cout<<"___________________________"<<endl;
    }

    return 0;
}