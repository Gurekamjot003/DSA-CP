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
    int calculate(string s) {
        stack<pair<bool, int>> st;
        ll cur_num = 0;
        bool neg = false;
        for(auto& ch: s){
            if(isdigit(ch)){
                cur_num = cur_num * 10 + ch-'0';
            }
            else{
                if(cur_num ){
                    if(neg) cur_num = -cur_num;
                    if(!st.empty() && st.top().first){
                        int prev_num = st.top().second;
                        st.pop();
                        st.push({1, prev_num + cur_num});
                    }
                    else st.push({1, cur_num});
                    cur_num = 0;
                    neg = false;
                }
                if(ch == '-'){
                    neg = true;
                }
                else if(ch == '('){
                    st.push({0, neg});
                    neg = false;
                }
                else if(ch == ')'){
                    int prev_sum = 0;
                    while(!st.empty() && st.top().first){
                        prev_sum += st.top().second;
                        st.pop();
                    }
                    if(!st.empty() && !st.top().first){
                        if(st.top().second) prev_sum = -prev_sum;
                        st.pop();
                    }
                    if(prev_sum) st.push({1, prev_sum});
                    neg = false;
                }
                else if(ch == '+'){
                    neg = false;
                }
            }

        }
        if(neg) cur_num = -cur_num;
        while(!st.empty()){
            cur_num += st.top().second;
            st.pop();
        }
        return cur_num;
    }
};

int main(){
    Solution sol;
    cout<<sol.calculate("5+3-4-(1+2-7+(10-1+3+5+(3-0+(8-(3+(8-(10-(6-10-8-7+(0+0+7)-10+5-3-2+(9+0+(7+(2-(2-(9)-2+5+4+2+(2+9+1+5+5-8-9-2-9+1+0)-(5-(9)-(0-(7+9)+(10+(6-4+6))+0-2+(10+7+(8+(7-(8-(3)+(2)+(10-6+10-(2)-7-(2)+(3+(8))+(1-3-8)+6-(4+1)+(6))+6-(1)-(10+(4)+(8)+(5+(0))+(3-(6))-(9)-(4)+(2))))))-1)))+(9+6)+(0))))+3-(1))+(7))))))))");
}