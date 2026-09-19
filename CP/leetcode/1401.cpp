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
    pair<bool, pair<double, double>> solve_eqn(int cur_center, int other_center, int other_val, int radius){
        // cout<<cur_center<<" "<<other_center<<" "<<other_val<<" "<<radius<<endl;
        double b = -2*cur_center, c = cur_center*cur_center + (other_val-other_center)*(other_val - other_center) - radius*radius;
        double a = 1;
        double D = b*b-4*a*c;
        // cout<<b<<" "<<c<<" "<<D<<endl;
        if(D<0) return {false, {}};
        // cout<<sqrt(D)<<endl;
        return {true, {(-b+sqrt(D))/2, (-b-sqrt(D))/2}};
    }

    bool check_for_values(int cur_center, int other_center, vector<int> vals_to_put, int radius, int min_val, int max_val){
        for(auto& other_val: vals_to_put){
            auto root_vals = solve_eqn(cur_center, other_center, other_val, radius);
            if(!root_vals.first) continue;
            auto [root1, root2] = root_vals.second;
            // cout<<root1<<" "<<root2<<endl;
            if((min_val<=root1 && max_val>=root1) or (min_val<=root2 && max_val>=root2)) return true;
        }
        return false;
    }

    double euclid_distance(int x1, int y1, int x2, int y2){
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    double check_corner_distance(int xCenter, int yCenter, vector<int>X, vector<int>Y, int radius){
        for(auto& x: X){
            for(auto& y: Y){
                if(euclid_distance(xCenter, yCenter, x, y) <= radius) return true;
            }
        }
        return false;
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(check_for_values(yCenter, xCenter, {x1, x2}, radius, y1, y2)) return true;
        if(check_for_values(xCenter, yCenter, {y1,y2}, radius, x1, x2)) return true;
        if(xCenter>=x1 && xCenter<=x2 && yCenter>=y1 && yCenter<=y2) return true;  // circle inside rectangle
        if(check_corner_distance(xCenter, yCenter, {x1, x2}, {y1, y2}, radius)) return true; // rectangle inside circle

        return false;
        

    }
};