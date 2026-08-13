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

vi wolf(vi& p, vvi& queries){
    vi location(p.size()+1);
    for(int i = 0; i<p.size(); i++){
        location[p[i]] = i+1;
    }
    vi ans;
    int n = p.size();
    for(auto& q: queries){
        int cur = 0;
        int l = q[0], r = q[1], k = q[2];
        int greater_used = 0, lesser_used = 0;
        int greater_req = 0, lesser_req = 0;
        int target_position = location[k];
        if((target_position) > r or (target_position) < l){
            ans.push_back(-1);
            continue;
        }
        
        while(l<=r){
            int mid = (l+r)/2;
            int index = mid-1;
            if(p[index] == k) break;
            if(target_position > mid){
                if(p[index] > k){
                    lesser_req++;
                }
                lesser_used++; 
                l = mid+1;
            }
            else{
                if(p[index] < k){
                    greater_req++;
                }
                greater_used++;
                r = mid-1;
            }
        }
        if(lesser_used > (k-1) or greater_used > (n-k)) ans.push_back(-1);
        else
            ans.push_back(max(greater_req, lesser_req)*2);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n, q; in >> n>>q;
        vi p(n);
        for(int i = 0; i<n; i++) in>>p[i];
        vvi queries(q, vi(3));
        for(int i = 0; i<q; i++){
            for(int j = 0; j<3; j++) in>>queries[i][j];
        }
        vi ans = wolf(p, queries);
        for(auto& n: ans) cout<<n<<" ";
        cout<<endl;
        // Your function call here
        // cout << program_name(parameters) << endl;
    }

    return 0;
}