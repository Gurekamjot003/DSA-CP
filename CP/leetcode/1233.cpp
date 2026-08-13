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

enum Folder{
    slash = 26
};

class Trie{
    vector<Trie*> next;
    bool is_end;
public:
    Trie(){
        next.resize(27, NULL);
        is_end = false;
    }

    void insert(string& path){
        Trie* node = this;
        for(auto& ch: path){
            int idx = (ch == '/'? slash: ch-'a');
            if(!node->next[idx]) node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->is_end = true;
    }

    static void dfs(Trie* root, string& cur_path, vector<string>& ans){
        int maxn = 27;
        if(root->is_end){
            ans.push_back(cur_path);
            maxn = 26;
        }
        rep(i, maxn){
            if(root->next[i]){
                char ch = (i==26? '/': i+'a');
                cur_path.push_back(ch);
                dfs(root->next[i], cur_path, ans);
                cur_path.pop_back();
            }
        }
    }
};




class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = new Trie();
        for(auto& path: folder) root->insert(path);
        vector<string> ans;
        string cur;
        Trie::dfs(root, cur, ans);
        return ans;
    }
};