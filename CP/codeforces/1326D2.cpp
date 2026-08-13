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

class Manacher{
    int max_palin;
    vi dp;
    string s;
    int n;

    void build(){
        int l = -1, r = 1;
        rep(i, n){
            int mirror = l + r - i;
            if(r>i && mirror >=0 && mirror <n) dp[i] = min(r-i, dp[mirror]);

            while((i-dp[i])>=0 && (i+dp[i])<n && s[i-dp[i]] == s[i+dp[i]]) dp[i]++;

            if((i+dp[i])>r){
                r = i+dp[i];
                l = i-dp[i];
            }
        }
    }

    void calc_max_palin(){
        max_palin = 0;
        int l = 0, r = n-1;
        
        while(l<=r && s[l] == s[r]){
            if(s[l] != '#') max_palin++;
            l++; r--;
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
        n = temp.size();
        dp.resize(n, 0);
        
        build();
        calc_max_palin();

        // for(auto n: dp) cout<<n<< " ";
        // cout<<endl;

        // cout<<max_palin<<endl;
    }

    string max_palindrome(){
        int max_size = 0;
        int index = 0;
        rep(i, n){
            int cur_size = dp[i]-1;
            int l = (i - cur_size )/2;
            int r = (n/2) - l - cur_size;
            // cout<<i<< " " <<l<<" "<<r<<endl;
            int rem_from_left_or_right = min(l, r);
            if(max_palin >= rem_from_left_or_right) cur_size += rem_from_left_or_right*2;
            else continue;
            if(cur_size>max_size){
                max_size = cur_size;
                index = i;
            }
        }

        int l = index - dp[index] + 1, r = index + dp[index] -1;
        string boundry;
        int cur_size = dp[index]-1;
        // cout<<index<<" "<<cur_size<<" "<<max_size<<endl;
        for(int i = 0; i<(max_size - cur_size); i++){
            if(s[i] != '#') boundry.push_back(s[i]);
        }
        string ans = boundry;
        for(int i = l; i<=r; i++) if(s[i] != '#') ans.push_back(s[i]);
        reverse(all(boundry));
        ans+= boundry;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        string s; in>>s;
        Manacher m(s);
        
        
        cout << m.max_palindrome() << endl;
    }
    return 0;
}