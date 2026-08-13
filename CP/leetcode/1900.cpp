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

    void backtrack(vi& nums, int first_player, int second_player, int n, vi& ans, int round, vi& cur, vector<vector<vvi>>& dp, int i = 0){
        int mirror = n-1-i;
        if(i>(mirror)){
            vi sorted = cur;
            sort(all(sorted));
            vi calc = solve(cur.size(), first_player, second_player, sorted, round+1, dp);
            amin(ans[0], calc[0]);
            amax(ans[1], calc[1]);
            return;
        }
        if((i == mirror) or (nums[mirror] != first_player && nums[mirror] != second_player)){
            cur.push_back(nums[i]);
            backtrack(nums, first_player, second_player, n, ans, round, cur,dp,  i+1);
            cur.pop_back();
        }
        if(nums[i] != first_player && nums[i] != second_player){
            cur.push_back(nums[mirror]);
            backtrack(nums, first_player, second_player, n, ans, round,cur,dp,  i+1);
            cur.pop_back();
        }
    }
    
    vi solve(int n, int first_player, int second_player, vi& nums, int round, vector<vector<vvi>>& dp){
        int pos1, pos2;
        for(int i = 0; i<n; i++){
            if(nums[i] == first_player){
                pos1 = i;
                int mirror = (n-1)-i;
                if(nums[mirror] == second_player) return{round,  round};
            }
            if(nums[i] == second_player) pos2 = i;
        }
        if(dp[round][pos1][pos2][0] != -1) return dp[round][pos1][pos2];
        
        vi ans = {INT_MAX, INT_MIN};
        vi cur;
        backtrack(nums, first_player, second_player, n, ans,round, cur, dp);

        return dp[round][pos1][pos2] = ans;
    }
public:

    vector<int> earliestAndLatest(int n, int first_player, int second_player) {

        vi nums(n);
            
        rep(i, n) nums[i] = i+1;
        vector<vector<vvi>> dp(n, vector<vvi>(n, vvi(n, {-1, -1})));
        return solve(n, first_player, second_player, nums, 1, dp);
        
    }
};

int main(){
    Solution sol;
    vi ans = sol.earliestAndLatest(23, 9, 20);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}