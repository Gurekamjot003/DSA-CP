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

pii get_count(vi freq){
    priority_queue<int> pq;
    rep(i, 26){
        if(freq[i]) pq.push(freq[i]);
    }

    int count = 0;
    int rem_count = 0;
    while(!pq.empty()){
        int freq1 = pq.top();
        pq.pop();
        if(pq.empty()){
            rem_count = freq1;
            break;
        }
        int freq2 = pq.top();
        pq.pop();
        count++;
        if(freq1>1) pq.push(freq1-1);
        if(freq2>1) pq.push(freq2-1);
    }
    return {count, rem_count};
}

class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<int> freq0(26), freq1(26);
        int both_x = 0;
        for(auto& card: cards){
            if(card[0] == x && card[1] == x) both_x++;
            else if(card[0] == x) freq0[card[1]-'a']++;
            else if(card[1] == x) freq1[card[0]-'a']++;
        }

        auto [count0, rem_count0] = get_count(freq0);
        auto [count1, rem_count1] = get_count(freq1);
        
        int ans = 0;
        int min0 = min(rem_count0, both_x);
        ans += min0;
        both_x -= min0;

        int min1 = min(rem_count1, both_x);
        ans += min1;
        both_x -= min1;

        both_x -= (both_x%2); // make it even

        count0 *= 2; count1*=2;
        min0 = min(count0, both_x);
        ans += min0;
        count0 -= min0;
        both_x-= min0;
        
        min1 = min(count1, both_x);
        ans += min1;
        count1 -= min1;
        both_x-= min1;

        ans += count0/2;
        ans += count1/2;

        return ans;
    }
};