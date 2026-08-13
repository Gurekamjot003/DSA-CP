//We have given a BST. In the tree, generally, we have two pointers i.e left and right but here they also provide another point named as parent pointer which is pointing to its parent. Consider a node containing left, right as well as parent pointer. Now they have given an integer 'K', the task to us is to find all the pairs in BST whose sum is K.


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

class BST{
public:
    int val;
    BST* left;
    BST* right;
    BST* parent;

    BST(int val): val(val){
        left = right = parent = nullptr;
    }

    
};

BST* insert(BST* root, int val){
    if(!root) return new BST(val);
    if(root->val>val){
        root->left = insert(root->left, val);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right, val);
        root->right->parent = root;
    }
    return root;
}

void display(BST* root){
    queue<BST*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            BST* u = q.front();
            q.pop();
            
            if(!u) cout<<"null"<<"\t";
            else{
                cout<<u->val<<",";
                if(u->parent) cout<<u->parent->val;
                else cout<<"NULL";
                cout<<"\t";
                q.push(u->left);
                q.push(u->right);
            }
            
        }
        cout<<endl;
    }
}

bool is_node_left_child_of_parent(BST* node){
    if(node->parent and node == node->parent->left) return true;
    return false;
}

void decrement(BST*& node){
    // go to right most node in left subtree
    if(node->left){
        node = node->left;
        while(node->right) node = node->right;
        return;
    }

    // go to parent having cur node as right child
    while(node->parent && is_node_left_child_of_parent(node)){
        node = node->parent;
    }
    node = node->parent;
}

void increment(BST*& node){
    if(node->right){
        node = node->right;
        while(node->left) node = node->left;
        return;
    }

    while(node->parent && !is_node_left_child_of_parent(node)){
        node = node->parent;
    }
    node = node->parent;
}

int find_count(BST* root, int target){
    if(!root) return 0;

    // taking 2 pointers on extreeme ends
    BST* smaller = root, *greater = root;
    while(smaller->left) smaller = smaller->left;
    while(greater->right) greater = greater->right;

    int ans = 0;
    while(smaller && greater && smaller->val < greater->val){
        if((smaller->val + greater->val) > target) decrement(greater);
        else if((smaller->val + greater->val) < target) increment(smaller);
        else{
            ans++;
            decrement(greater);
            increment(smaller);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    vi nums = {5, 1, 3, 2, 9, 4, 10, 20};
    BST* root = nullptr;
    for(auto& n: nums){
        root = insert(root, n);
    }
    display(root);
    
    cout<<find_count(root, 13);

    return 0;
}