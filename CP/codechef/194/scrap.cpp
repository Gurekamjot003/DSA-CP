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

int mod = 1e9 +7;
class Fenwick{
    vll bit;
    int n;
public:
    Fenwick(vi& arr){
        n = arr.size();
        bit.resize(n+2);
        
    }

    void update(int id, ll val){
        while(id<=n){
            bit[id]+=val;
            bit[id]%=mod;
            id += (id & -id);
        }
    }

    ll query(int id){
        ll ans = 0;
        while(id>0){
            ans += 0ll+bit[id];
            ans %= mod;
            id -= (id&-id);
        }
        return ans;
    }
};

ll calculate_for_section(int start, int end, vi& a, Fenwick& BIT){
    int sub = (start>0? BIT.query(a[start]): 0);
    ll ans = 0;
    for(int i = start; i<=end; i++){
        ll val = BIT.query(a[i])- sub+1;
        ans += val;
        ans %= mod;
        BIT.update(a[i], val);
    }
    return ans;

}

ll solve(vi& a, int n){
    int cur_max = INT_MIN;
    ll ans = 1;
    int prev = 0;
    Fenwick BIT(a);
    rep(i, n){

        amax(cur_max, a[i]);
        if(cur_max<=(i+1)){
            ll mul = calculate_for_section(prev, i, a, BIT);
            // cout<<mul<<" ";
            ans *= mul;
            ans %= mod;
            prev = i+1;
        } 
    }
    return ans;
}

static const int MOD = 1e9+7;

// ——————————— Your implementation ———————————

ll solve_user_single(vector<int>& a) {
    
    return solve(a, a.size());
}

// ————————— Reference implementation ———————————
ll solve_ref_single(const vector<int>& a){
    int n = a.size();
    // split into irreducible blocks, for each do a fresh Fenwick
    struct Fen {
        int n; vector<int> f;
        Fen(int _n):n(_n),f(n+1,0){}
        void update(int i,int v){
            for(i++; i<=n; i+=i&-i){
                f[i]=(f[i]+v)%MOD;
            }
        }
        int query(int i){
            int s=0;
            for(i++;i>0;i-=i&-i)
                s=(s+f[i])%MOD;
            return s;
        }
    };
    auto count_block = [&](int L,int R){
        int len = R-L+1;
        Fen fw(len);
        int minv = *min_element(a.begin()+L,a.begin()+R+1);
        ll total=0;
        for(int i=L;i<=R;i++){
            int idx = a[i]-minv;
            ll smaller = fw.query(idx-1);
            ll dp = (smaller+1)%MOD;
            fw.update(idx, dp);
            total = (total + dp)%MOD;
        }
        return total;
    };

    ll ans=1; int curmax=0, last=0;
    for(int i=0;i<n;i++){
        curmax = max(curmax, a[i]);
        if(curmax==i+1){
            if(i-last+1>1){
                ll ways = count_block(last,i);
                ans = ans*ways%MOD;
            }
            last = i+1;
        }
    }
    return ans;
}

// ———————— Stress Test Harness —————————
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(1234);
    const int MAXN = 100;      // you can increase up to ~100 safely
    const int ITERS = 100000;

    for(int it=1; it<=ITERS; ++it){
        int n = uniform_int_distribution<int>(1,MAXN)(rng);
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        shuffle(perm.begin(), perm.end(), rng);

        ll u = solve_user_single(perm);
        ll r = solve_ref_single(perm);
        if(u!=r){
            cout<<"Mismatch on test #"<<it<<"\n";
            cout<<"n="<<n<<" perm =";
            for(int x:perm) cout<<" "<<x;
            cout<<"\nuser output = "<<u<<"\n";
            cout<<"ref  output = "<<r<<"\n";
            return 0;
        }
    }
    cout<<"OK — all "<<ITERS<<" random tests matched.\n";
    return 0;
}
