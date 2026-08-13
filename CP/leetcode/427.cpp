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


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
    int n, m;
    Node* construct_in_range(vvi& grid, int i, int j, int max_row, int max_col){

        if(i == (max_row-1)){
            return new Node(grid[i][j], true);
        }
        int row_mid = (i+max_row)/2, col_mid = (j+max_col)/2;
        Node* top_left = construct_in_range(grid, i, j, row_mid, col_mid),
            * top_right = construct_in_range(grid, i, col_mid, row_mid, max_col),
            * bottom_left = construct_in_range(grid, row_mid, j, max_row, col_mid),
            * bottom_right = construct_in_range(grid, row_mid, col_mid, max_row, max_col);
        
        if(top_left->isLeaf && 
           top_right ->isLeaf &&
           bottom_left->isLeaf &&
           bottom_right->isLeaf &&
           top_left->val == top_right->val && 
           top_right->val == bottom_left->val &&
           bottom_left->val == bottom_right->val
        ){
            Node* combined = new Node(top_left->val, true);
            delete top_left, top_right, bottom_left, bottom_right;
            return combined;
        }

        Node* combined = new Node(1, false, top_left, top_right, bottom_left, bottom_right);
        return combined;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        n = grid.size(); m= grid[0].size();
        return construct_in_range(grid, 0, 0, n, m);
    }
};

int main(){
    Solution sol;
    vvi grid = {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };

    Node* ans = sol.construct(grid);
    queue<Node*> q;
    q.push(ans);
    
    while(!q.empty()){
        Node* u = q.front();
        q.pop();

        cout<<u->val<<" "<<u->isLeaf<<endl;
        if(!u->isLeaf){
            q.push(u->topLeft);
            q.push(u->topRight);
            q.push(u->bottomLeft);
            q.push(u->bottomRight);
        }
    }

}