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

template<class T>
class MaxSegmentTree{
    vector<T> tree;
    vector<T> arr; // The original array for which the segment tree is built

    // Function to initialize a leaf node in the segment tree
    // For a sum segment tree, it's just the value itself.
    T init_leaf(int index){
        return arr[index];
    }

    // Function to combine results from two child nodes
    // For a sum segment tree, it's addition.
    T combine(T val_1, T val_2){
        return max(val1, val2);
    }

    // Helper function for updating a value in the segment tree
    // target_index: index in the original array to update
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    void update_helper(int target_index, int left, int right, int index = 0){
        if(left == right){
            // Leaf node reached, update its value
            tree[index] = init_leaf(target_index);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;

        // Recurse into the appropriate child
        if(target_index<=mid) update_helper(target_index, left, mid, left_child);
        else update_helper(target_index, mid+1, right, right_child);

        // Update the current node's value based on its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Helper function for querying a range in the segment tree
    // q_left, q_right: query range
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    T query_helper(int q_left, int q_right, int left, int right, int index = 0){
        // Case 1: Current segment is completely within the query range
        if(left>=q_left && right<=q_right) return tree[index];
        // Case 2: Current segment is completely outside the query range
        if(left>q_right or right<q_left) return (T)0;
        // Case 3: Current segment partially overlaps with the query range
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Combine results from left and right children
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid+1, right, right_child)); 
    }

public:
    // Constructor
    MaxSegmentTree(const vector<T>& initial_arr){ // Use const reference for initial array
        int sz = initial_arr.size();
        tree.resize(sz*4);
        this->arr = initial_arr; // Copy the initial array
        // Start building the tree from the root (index 0) covering the entire array range
        build(0, 0, sz-1);
    }

    // Function to build the segment tree
    // index: current node index in the 'tree' vector
    // left, right: current segment range covered by the 'index' node
    void build(int index, int left, int right){
        if(left == right){
            // Leaf node: store the value from the original array
            tree[index] = init_leaf(left);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Recursively build left and right subtrees
        build(left_child, left, mid);
        build(right_child, mid + 1, right);
        
        // Current node's value is combined from its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Public method to update a value in the original array and propagate changes to the tree
    void update(int data_index, T value){
        arr[data_index] = value; // Update the original array
        update_helper(data_index, 0, arr.size()-1); // Call helper to update the tree
    }

    // Public method to query the sum (or other aggregate) for a given range
    T get_value(int q_left, int q_right){
        // Call helper to perform the query on the tree
        return query_helper(q_left, q_right, 0, arr.size()-1);
    }

};
template<class T>
class MinSegmentTree{
    vector<T> tree;
    vector<T> arr; // The original array for which the segment tree is built

    // Function to initialize a leaf node in the segment tree
    // For a sum segment tree, it's just the value itself.
    T init_leaf(int index){
        return arr[index];
    }

    // Function to combine results from two child nodes
    // For a sum segment tree, it's addition.
    T combine(T val_1, T val_2){
        return min(val1, val2);
    }

    // Helper function for updating a value in the segment tree
    // target_index: index in the original array to update
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    void update_helper(int target_index, int left, int right, int index = 0){
        if(left == right){
            // Leaf node reached, update its value
            tree[index] = init_leaf(target_index);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;

        // Recurse into the appropriate child
        if(target_index<=mid) update_helper(target_index, left, mid, left_child);
        else update_helper(target_index, mid+1, right, right_child);

        // Update the current node's value based on its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Helper function for querying a range in the segment tree
    // q_left, q_right: query range
    // left, right: current segment range covered by the 'index' node
    // index: current node index in the 'tree' vector
    T query_helper(int q_left, int q_right, int left, int right, int index = 0){
        // Case 1: Current segment is completely within the query range
        if(left>=q_left && right<=q_right) return tree[index];
        // Case 2: Current segment is completely outside the query range
        if(left>q_right or right<q_left) return (T)0;
        // Case 3: Current segment partially overlaps with the query range
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Combine results from left and right children
        return combine(query_helper(q_left, q_right, left, mid, left_child), query_helper(q_left, q_right, mid+1, right, right_child)); 
    }

public:
    // Constructor
    MinSegmentTree(const vector<T>& initial_arr){ // Use const reference for initial array
        int sz = initial_arr.size();
        tree.resize(sz*4);
        this->arr = initial_arr; // Copy the initial array
        // Start building the tree from the root (index 0) covering the entire array range
        build(0, 0, sz-1);
    }

    // Function to build the segment tree
    // index: current node index in the 'tree' vector
    // left, right: current segment range covered by the 'index' node
    void build(int index, int left, int right){
        if(left == right){
            // Leaf node: store the value from the original array
            tree[index] = init_leaf(left);
            return;
        }
        int mid = (left+right)/2;
        int left_child = index*2 + 1, right_child = index*2 + 2;
        // Recursively build left and right subtrees
        build(left_child, left, mid);
        build(right_child, mid + 1, right);
        
        // Current node's value is combined from its children
        tree[index] = combine(tree[left_child], tree[right_child]);
    }

    // Public method to update a value in the original array and propagate changes to the tree
    void update(int data_index, T value){
        arr[data_index] = value; // Update the original array
        update_helper(data_index, 0, arr.size()-1); // Call helper to update the tree
    }

    // Public method to query the sum (or other aggregate) for a given range
    T get_value(int q_left, int q_right){
        // Call helper to perform the query on the tree
        return query_helper(q_left, q_right, 0, arr.size()-1);
    }

};

vi solve(){
    istream& in = getInputStream();
    int n, m; in>>n>>m;
    vi a(n);
    rep(i, n) in>>a[i];
    vvi queries(m);
    rep(i, m){
        in>>queries[i][0]>>queries[i][1];
    }

    MaxSegmentTree st_max(a);
    MinSegmentTree st_min(a);

    for(auto& q: queries){
        int l = q[0], r = q[1];
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    vi ans = solve();
    for(auto& n: ans) cout<<n<<" ";
    
    return 0;
}