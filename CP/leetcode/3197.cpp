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

class Rectangle{
    int left, right, top, bottom, area;
public:
    Rectangle():left(INT_MAX), right(INT_MIN), top(INT_MAX), bottom(INT_MIN), area(1){}
    
    void insert_point(int i, int j){
        amin(left, j);
        amin(top, i);
        amax(right, j);
        amax(bottom, i);
        update_area();
    }

    void update_area(){
        area = (right - left + 1)*(bottom - top + 1);
    }

    void add_row(int row, int col_start, int col_end, vvi& grid){
        int d = (col_start>col_end? -1: 1);
        for(int col= col_start; col<col_end; col+=d){
            if(grid[row][col]) insert_point(row, col);
        }
    }

    void add_column(int row_start, int row_end, int col, vvi& grid){
        int d = (row_start>row_end? -1: 1);
        for(int row = row_start; row<row_end; row+=d){
            if(grid[row][col]) insert_point(row, col);
        }
    }

    int get_area(){
        return area;
    }
};

class Solution {
    int n, m;

    int pattern_12(vvi& grid){

        int ans = INT_MAX;
        Rectangle top_rect;
        
        for(int i = 0; i<n-1; i++){ // inclusive for top
            top_rect.add_row(i, 0, m, grid);

            // precompute areas for bottom right
            stack<int> bottom_right_areas;
            Rectangle bottom_right_rect;
            for(int c = m-1; c>0; c--){
                bottom_right_rect.add_column(i+1, n, c, grid);
                bottom_right_areas.push(bottom_right_rect.get_area());
            }
            
            // compute running areas for both bottom left & right
            Rectangle bottom_left_rect;
            for(int c = 0; c<m-1; c++){
                bottom_left_rect.add_column(i+1, n, c, grid);
                amin(ans, top_rect.get_area() + bottom_left_rect.get_area() + bottom_right_areas.top());
                bottom_right_areas.pop();
            }
        }
        return ans;
    }
    
    int pattern_111(vvi& grid){

        int ans = INT_MAX;
        Rectangle top_rect;
        
        for(int i = 0; i<n-2; i++){ // inclusive for top
            top_rect.add_row(i, 0, m, grid);
    
            // precompute areas for bottom 
            stack<int> bottom_areas;
            Rectangle bottom_rect;
            for(int r = n-1; r>(i+1); r--){
                bottom_rect.add_row(r, 0, m, grid);
                bottom_areas.push(bottom_rect.get_area());
            }
            
            // compute running areas for both bottom mid & bottom
            Rectangle mid_rect;
            for(int r = i+1; r<(n-1); r++){
                mid_rect.add_row(r, 0, m, grid);
                amin(ans, top_rect.get_area() + mid_rect.get_area() + bottom_areas.top());
                bottom_areas.pop();
            }
    
        }
        return ans;
        
    }
    
    void rotate_90(vvi& grid){
        vvi ans(m, vi(n));
        rep(i, n){
            rep(j, m){
                ans[j][n-1-i] = grid[i][j];
            }
        }
        swap(n, m);
        grid = ans;
    }
    
    void display_grid(vvi& grid){
        cout<<"\n\nGrid:"<<endl;
        for(auto& n: grid){
            for(auto& m: n) cout<<m<<" ";
            cout<<endl;
        }
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = INT_MAX;
        
        // case 1 top full, bottom left + right
        amin(ans, pattern_12(grid));
        
        // case 2 top, mid, bottom
        amin(ans, pattern_111(grid));

        // rotate 
        rotate_90(grid);

        //case 3 left, top right, bottom right
        amin(ans, pattern_12(grid));

        // case 4 left, mid, right
        amin(ans, pattern_111(grid));

        // rotate
        rotate_90(grid);

        //case 5 top left, top right, bottom
        amin(ans, pattern_12(grid));

        // rotate
        rotate_90(grid);

        // case 6 top left, bottom left, right
        amin(ans, pattern_12(grid));
        
        return ans;
    }
};