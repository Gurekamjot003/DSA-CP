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
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflicting_pairs) {
        // smaller on right
        for(auto& n: conflicting_pairs){
            if(n[0]<n[1]) swap(n[0], n[1]);
        }
        sort(all(conflicting_pairs));
        ll ans = 0;

        //improvements[i] will store count extra subarrays we can add by removing cur conf pair
        vll improvements(conflicting_pairs.size()+1);
        conflicting_pairs.insert(conflicting_pairs.begin(), {0, 0}); //removing validations

        int cp_ptr = 0;
        int left = 0, sec_left = 0; //nearest left and second conflicting pairs whose right have been crossed

        rep1(i, n){
            //check for values whose right have been crossed and update left & sec left
            while(cp_ptr<conflicting_pairs.size() && i>=conflicting_pairs[cp_ptr][0]){
                vi & cur_pair = conflicting_pairs[cp_ptr];
                if(cur_pair[1]>=conflicting_pairs[left][1]){
                    sec_left = left;
                    left = cp_ptr;
                }
                else if(cur_pair[1] >=conflicting_pairs[sec_left][1]){
                    sec_left = cp_ptr;
                }
                cp_ptr++;
            }

            //no improvement directly added to ans 
            ans += i - conflicting_pairs[left][1];
            //improvement for diff left & sec left
            improvements[left] += conflicting_pairs[left][1] - conflicting_pairs[sec_left][1];
        }
        //we can have max improvement from all conf pairs
        return ans + *max_element(all(improvements));
    }
};