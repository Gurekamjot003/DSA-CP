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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller_list = new ListNode();
        ListNode* greater_list = new ListNode();
        ListNode* s = smaller_list, *g = greater_list;
        ListNode* cur = head;
        while(cur){
            if(cur->val<x){
                s->next = cur;
                s = s->next;
            }
            else{
                g->next = cur;
                g = g->next;
            }
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = NULL;
        }

        s->next = greater_list->next;
        return smaller_list->next;
        
    }
};


int main(){
    vi nodes = {1,4,3,2,5,2};
    ListNode* head = new ListNode(nodes[0]);
    ListNode* cur = head;
    rep1(i, nodes.size()-1){
        cur->next = new ListNode(nodes[i]);
        cur = cur->next;
    }

    Solution sol;
    ListNode* ans = sol.partition(head, 3);
    
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<endl<<endl;
    nodes = {2,1};
    head = new ListNode(nodes[0]);
    cur = head;
    rep1(i, nodes.size()-1){
        cur->next = new ListNode(nodes[i]);
        cur = cur->next;
    }

    ans = sol.partition(head, 2);
    
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<endl<<endl;
}