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


#include<bits/stdc++.h>
using namespace std;

class Manacher{
    vector<int> dp;
    string s;

    void build(){
        int l = -1, r =1;
        int n = s.size();
        for(int i = 1; i<n; i++){

            //init using mirror
            int mirror = l +r -i;
            if(i<r && mirror >=0 && mirror <n) dp[i] = max(0, min(r - i, dp[mirror]));

            //inc until match found
            while((i-dp[i])>=0 && (i+dp[i])<s.size() && s[i+dp[i]] == s[i-dp[i]]) dp[i]++;
            
            //slide window if palindrome is long enough
            if((i+dp[i])>r){
                r = i+dp[i];
                l = i-dp[i];
            }
        }
    }

public:
    Manacher(string s){
       
        string temp;
        for(auto& ch: s){
            temp.push_back('#');
            temp.push_back(ch);
        }
        temp.push_back('#');
        this->s = temp;
        dp.resize(temp.size(),0);
        build();
    }

    int longest_palindrome_length(){
        int ans = 1;
        for(int i = 1; i<s.size(); i++){
            ans = max(ans, dp[i]);
        }
        return ans -1;
    }

    int longest_palindrome_index(){
        int max_len = longest_palindrome_length();
        for(int i = 0; i<s.size(); i++){
            if(dp[i] > max_len) return i;
        }
        return -1;
    }

    string longest_palindrome(){
        string ans;
        int index = longest_palindrome_index();
        int left = index - dp[index] + 1;
        int right = index + dp[index] - 1;
        for(; left<=right; left++) if(s[left] != '#') ans.push_back(s[left]);
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        Manacher m(s);
        return m.longest_palindrome();
    }
};
