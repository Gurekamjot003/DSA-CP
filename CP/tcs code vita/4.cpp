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

pair<bool, int> get_num(string cur){
    if(cur == "one") return {true, 1};
    if(cur == "two") return {true, 2};
    if(cur == "three") return {true, 3};
    if(cur == "four") return {true, 4};
    if(cur == "five") return {true, 5};
    if(cur == "six") return {true, 6};
    if(cur == "seven") return {true, 7};
    if(cur == "eight") return {true, 8};
    if(cur == "nine") return {true, 9};
    if(cur == "zero") return {true, 0};
    return {false, 0};
}

pair<bool, int> get_operand(string& s){
    string cur;
    int ans = 0;
    for(int i= 0; i<(int)s.size(); i++){
        if(s[i] == 'c'){
            auto num = get_num(cur);
            if(!num.first) return {0, 0};
            ans = ans*10 +  num.second;
            cur = "";
        }
        else cur.push_back(s[i]);
    }
    auto num = get_num(cur);
    if(!num.first) return {0, 0};
    ans = ans*10 +  num.second;
    return {1, ans};
}

pair<bool, int> calc(int a, int b, int operation){
    if(operation == 1) return {1, a + b};
    if(operation == 2) return {1, a - b};
    if(operation == 3) return {1, a * b};
    if(operation == 4){
        if(b == 0) return {0, 0};
        return {1, a % b};
    }
    if(operation == 5) return {1,pow(a, b)};
    return {0, 0};

}

pair<bool, int> get_operator(string& cur){
    if(cur == "add") return {1, 1};
    if(cur == "sub") return {1, 2};
    if(cur == "mul") return {1, 3};
    if(cur == "rem") return {1, 4};
    if(cur == "pow") return {1, 5};
    return {0, 0};
}

bool operate(stack<pii>& st, int cur_num, bool is_operand){
    if(is_operand){
        if(!st.empty() && st.top().first){
            int a = st.top().second; st.pop();
            if(st.empty() or st.top().first) return false;
            int operation = st.top().second;
            st.pop();
            auto res = calc(a, cur_num, operation);
            if(!res.first) return false;
            st.push({1, res.second});
        }
        else{
            st.push({1, cur_num});
        }
    }
    else{
        st.push({0, cur_num});
    }
    return true;
}

bool invalid = false;

void solve(string& s){
    stack<pii> st;
    string cur;
    int cur_num = 0;
    bool is_operand = false;
    for(int i= 0; i<(int)s.size(); i++){
        if(s[i] == ' '){
            auto op = get_operator(cur);
            if(op.first){
                operate(st, op.second, false);
                cur = "";
                continue;
            }
            
            auto num = get_operand(cur);
            bool valid = true;
            if(num.first){
                valid &= operate(st, num.second, true);
                if(!valid) invalid = true;
            }
            else{
                cout<<"expression evaluation stopped invalid words present";
                return;
            }
            cur = "";
        }
        else cur.push_back(s[i]);
    }
    auto op = get_operator(cur);
    if(op.first){
        operate(st, op.second, false);
        cout<<"expression is not complete or invalid";
        return;
    }
    
    auto num = get_operand(cur);
    bool valid = true;
    if(num.first){
        valid &= operate(st, num.second, true);
        if(!valid) invalid = true;
    }
    else{
        cout<<"expression evaluation stopped invalid words present";
        return;
    }
    
    cur = "";
    
    if(st.size() != 1 or !st.top().first){
        invalid = true;    
    }
    if(invalid){
        cout<<"expression is not complete or invalid";
        return;
    }
    cout<<st.top().second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    string s;
    getline(in, s);
    solve(s);
    return 0;
}