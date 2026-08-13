#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 69;

struct node{
    int sum, cnt;
};

int n;
string s[2];
node seg[2][4 * N];

node combine(node a, node  b){
    node c;
    c.sum = a.sum + b.sum;
    c.cnt = a.cnt + b.cnt;
    return c;
}

node init(char ch, int pos){
    node c;
    if (ch == '1'){
        c.sum = pos;
        c.cnt = 1;
    } else {
        c.sum = c.cnt = 0;
    }
    return c;
}

void build(int l, int r, int pos, int i){
    if (l == r){
        seg[i][pos] = init(s[i][l], l);
        return;
    }
    
    int mid = (l + r) / 2;
    build(l, mid, pos * 2, i);
    build(mid + 1, r, pos * 2 + 1, i);
    
    seg[i][pos] = combine(seg[i][pos * 2], seg[i][pos * 2 + 1]);
}

void upd(int l, int r, int pos, int qp, int i){
    if (l == r){
        seg[i][pos] = init(s[i][l], l);
        return;
    }
    
    int mid = (l + r) / 2;
    if (qp <= mid) upd(l, mid, pos * 2, qp, i);
    else upd(mid + 1, r, pos * 2 + 1, qp, i);
    
    seg[i][pos] = combine(seg[i][pos * 2], seg[i][pos * 2 + 1]);
}

int find_kth(int l, int r, int pos, int k, int i){
    if (l == r){
        return l;
    }
    
    int mid = (l + r) / 2;
    if (k <= seg[i][pos * 2].cnt){
        return find_kth(l, mid, pos * 2, k, i);
    } else {
        return find_kth(mid + 1, r, pos * 2 + 1, k - seg[i][pos * 2].cnt, i);
    }
}

node res;

void query(int l, int r, int pos, int ql, int qr, int i){
    if (l >= ql && r <= qr){
        res = combine(res, seg[i][pos]);
    } else if (l > qr || r < ql){
        
    } else {
        int mid = (l + r) / 2;
        
        query(l, mid, pos * 2, ql, qr, i);
        query(mid + 1, r, pos * 2 + 1, ql, qr, i);
    }
}

void Solve() 
{
    int q;
    cin >> n >> q;
    
    cin >> s[0] >> s[1];
    reverse(s[1].begin(), s[1].end());
    s[0] = "0" + s[0];
    s[1] = "0" + s[1];
    
    int c0 = 0, c1 = 0;
    for (auto x : s[0]){
        c0 += x == '1';
    }
    for (auto x : s[1]){
        c1 += x == '1';
    }
    
    build(1, n, 1, 0);
    build(1, n, 1, 1);
    
    auto calc = [&](){
        if (c0 + c1 <= n){
            cout << -1 << "\n";
            return;
        }  
        
        int lo = n + 1 - c1;
        int hi = c0;
        
        while (lo != hi){
            int mid = (lo + hi + 1) / 2;
            
            int v1 = mid;
            int v2 = n + 1 - mid;
            
            int p1 = find_kth(1, n, 1, v1, 0) - v1;
            int p2 = find_kth(1, n, 1, v2, 1) - v2;
            
            if (p1 > p2){
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        
        int ans = INF;
        
        auto work = [&](int x){
            int v1 = x;
            int v2 = n + 1 - x;
            
            int p1 = find_kth(1, n, 1, v1, 0);
            int p2 = find_kth(1, n, 1, v2, 1);
            
            int val = 0;
            res.sum = res.cnt = 0;
            query(1, n, 1, 1, p1, 0);
            val += res.sum;
            res.sum = res.cnt = 0;
            query(1, n, 1, 1, p2, 1);
            val += res.sum;
            
            val -= v1 * (v1 + 1) / 2;
            val -= v2 * (v2 + 1) / 2;
            
            ans = min(ans, val);
        };
        
        work(lo);
        if (lo + 1 <= c0){
            work(lo + 1);
        }
        
        cout << ans << "\n";
    };
    
    calc();
    
    while (q--){
        int x, y; cin >> x >> y;
        x--;
        
        if (x == 1){
            y = n + 1 - y;
        }
        
        if (x == 0){
            c0 -= s[0][y] == '1';
            c0 += !(s[0][y] == '1');
            s[0][y] ^= '0' ^ '1';
            
            upd(1, n, 1, y, 0);
        } else {
            c1 -= s[1][y] == '1';
            c1 += !(s[1][y] == '1');
            s[1][y] ^= '0' ^ '1';
            
            upd(1, n, 1, y, 1);
        }
        
        calc();
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}