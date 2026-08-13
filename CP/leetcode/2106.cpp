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
    int find_greater(vvi& fruits, int target){
    
        int left = 0, right = n-1;
        int ans = right;
        while(left<=right){
            int mid = (left+right)/2;
            if(fruits[mid][0]<target){
                left = mid+1;
            }
            else{
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }

    int find_lesser(vvi& fruits, int target){
    
        int left = 0, right = n-1;
        int ans = left;
        while(left<=right){
            int mid = (left+right)/2;
            if(fruits[mid][0]<=target){
                left = mid+1;
                ans = mid;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start_pos, int k) {
        n = fruits.size();
        fruits.insert(fruits.begin(), {-1, 0});
        fruits.push_back({(int)1e6, 0});
        n+=2;
        int left_pos = find_greater(fruits, start_pos-k);
        int diff = fruits[left_pos][0] - (start_pos-k);
        int right_pos = find_lesser(fruits, start_pos + diff/2 );

        int ans = 0;

        // left to start_pos window
        int window_sum = 0;
        for(int i = left_pos; i<=right_pos; i++){
            window_sum += fruits[i][1];
        }
        amax(ans, window_sum);
        
        while(fruits[left_pos][0]<=start_pos && left_pos<right_pos){
            window_sum -= fruits[left_pos++][1];
            diff = fruits[left_pos][0] - (start_pos-k);
            while(right_pos<(n-1) && fruits[right_pos+1][0]<=(start_pos + diff/2)){
                window_sum += fruits[++right_pos][1];
            }
            amax(ans, window_sum);
        }
        
        // start_pos to right window
        right_pos = find_lesser(fruits,start_pos+k);
        diff = (start_pos+k)-fruits[right_pos][0];
        left_pos = find_greater(fruits, start_pos - diff/2);
        window_sum = 0;
        for(int i = left_pos; i<=right_pos; i++){
            window_sum += fruits[i][1];
        }
        amax(ans, window_sum);
        while(fruits[right_pos][0]>=start_pos && left_pos<right_pos){
            window_sum -= fruits[right_pos--][1];
            diff = (start_pos+k)-fruits[right_pos][0];
            while(left_pos>0 && fruits[left_pos-1][0]>=(start_pos - diff/2)){
                window_sum += fruits[--left_pos][1];
            }
            amax(ans, window_sum);
        }

        return ans;
    }
};