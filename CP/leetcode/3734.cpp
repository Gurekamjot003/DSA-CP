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
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        string ans;
        int best_idx = -1, char_at_best;
        vi s_freq(26);
        rep(i, n) s_freq[s[i]-'a']++;
        bool one_freq_present = false; 
        int ch = '\n';
        rep(i, 26){
            if(s_freq[i]%2){
                if(one_freq_present) return ans;
                else{
                    one_freq_present = true;
                    ch = i;
                }
            }
        }

        vi freq = s_freq;
        bool same_pos = true;
        rep(i, n/2){
            // if greater than that is present then it is a potential answer
            for(int ch = target[i]-'a'+1; ch<='z'-'a'; ch++){
                if(freq[ch]>1){
                    best_idx = i;
                    char_at_best = ch;
                    break;
                }
            }
            if(freq[target[i]-'a'] <= 1){
                same_pos = false;
                break; // same not possible
            }
            freq[target[i]-'a']-=2;
        }
        if(same_pos){
            string to_check = target;
            if(n%2) to_check[n/2] = ch+'a';
            for(int i = 0; i<n/2; i++) to_check[n-1-i] = to_check[i];
            if(to_check>target) return to_check;
        }

        if(best_idx == -1) return "";

        freq = s_freq;
        ans = target;
        if(n%2){
            ans[n/2] = ch+'a';
            freq[ch]--;
        }
        ans[best_idx] = char_at_best+'a';
        rep(i, best_idx+1) freq[ans[i]-'a']-=2;
        ch = 0;
        for(int i = best_idx+1; i<n/2; i++){
            while(ch<26 && freq[ch] == 0) ch++;
            ans[i] = ch+'a';
            freq[ch]-=2;
        }
        for(int i=  0; i<n/2; i++){
            ans[n-1-i] = ans[i];
        }
        
        return ans;
    }
};