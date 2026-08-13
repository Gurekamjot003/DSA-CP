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

class Node{
    public:
    // Value stored in the node
    int val, height, count;
    // Pointers to left and right children
    Node *left, *right;
    Node(int value){
        val = value;
        height = count = 1;
        left = right = NULL;
    }
};

int get_height(Node* root){
    // Returns the height of the node, 0 if null
    if(!root) return 0;
    return root->height;
}

int get_balance(Node* root){
    // Calculates the balance factor (height of left subtree - height of right subtree)
    return get_height(root->left) - get_height(root->right);
}

// Performs a left rotation on the given node
Node* left_rotation(Node* root){
    Node* child = root->right;
    Node* child_left = child->left;

    child->left = root;
    root->right = child_left;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    
    return child;
}

// Performs a right rotation on the given node
Node* right_rotation(Node* root){
    Node* child = root->left;
    Node* child_right = child->right;
    
    child->right = root;
    root->left = child_right;
    
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));

    return child;    
}

Node* insert(Node* root, int n){
    if(!root) return new Node(n);

    if(n< root->val) root->left = insert(root->left, n);
    else if( n> root->val) root->right = insert(root->right, n);
    else{
        root->count++;
        return root;
    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int balance = get_balance(root);

    if(balance>1){
        // LL case
        if(n < root->left->val){
            root = right_rotation(root);
        }
        // LR case
        else{
            root->left = left_rotation(root->left);
            root = right_rotation(root);
        }
    }
    else if(balance < (-1)){
        // RR case
        if(n>root->right->val){
            root = left_rotation(root);
        }
        // RL case
        else{
            root->right = right_rotation(root->right);
            root = left_rotation(root);
        }
    }
    // balanced 
    
    return root;

}

Node* del(Node* root, int n){
    if(!root) return NULL;
    if(n>root->val) root->right = del(root->right, n);
    else if(n<root->val) root->left = del(root->left, n);
    else{
        if(root->count>1){
            root->count--;
            return root;
        }
        //both children
        if(root->left && root->right){
            Node* left_max = root->left;
            while(left_max->right){
                left_max = left_max->right;
            }
            root->val = left_max->val;
            root->left = del(root->left, left_max->val);
        }   
        //single child
        else if(root->left or root->right){
            Node* child = root->left;
            if(!child) child = root->right;
            delete root;
            return child;
        }
        //Leaf node
        else{
            delete root;
            return NULL;
        }

    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int balance = get_balance(root);
    //left side
    if(balance>1){
        int left_balance = get_balance(root->left);
        if(left_balance<0) root->left = left_rotation(root->left);
        root = right_rotation(root);
    }
    //right side
    else if(balance < (-1)){
        // Right subtree is heavier
        int right_balance = get_balance(root->right);
        if(right_balance > 0) root->right = right_rotation(root->right);
        root = left_rotation(root);
    }
    // Return the (potentially new) root of the subtree
    return root;
}

int search(Node* root, ll target){
    ll ans = INT64_MAX;
    while(root){
        if(root->val >= target){
            ans = min<ll>(ans, root->val);
            root = root->left; // search for smaller
        }
        else root = root->right;
    }
    return ans;
}

vll solve(vi& b, int n){
    ll sum = accumulate(all(b), 0ll); 
    if(sum<=0) return {-1};
    Node* root = nullptr;
    for(auto& n: b){
        root = insert(root, n);
    }
    ll cur = 0;
    vll ans(n);
    rep(i, n){
        int b_val = search(root, 1-cur);
        cur += b_val;
        ans[i] = cur;
        root = del(root, b_val);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vi b(n);
        rep(i, n) in>>b[i];
        vll ans = solve(b, n);
        for(auto& n: ans) cout<<n<<" ";
        cout<<endl;
    }
    return 0;
}