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
#define endl "\n"
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

void push_into_queue(vvi& graph, int u, queue<int>& q){
    for(auto& v: graph[u]){
        q.push(v);
    }
}

vvi make_graph(vi& a, int n){
    vvi graph(n+1);
    for(int i = 0; i<2*n; i+=2){
        graph[a[i]].push_back(a[i+1]);
        graph[a[i+1]].push_back(a[i]);
    }
    return graph;
}

void dfs(int& ans, vi& a, vvi& graph, int n, vb& completed, int u){

    if(completed[u]){
        return;
    }
    completed[u] = true;
    ans++;
    for(auto& v: graph[u]){
        dfs(ans, a, graph, n, completed, v);
    }
}

class DisjointSet{
    vi parent;
public:
    vi size;
    
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 0);
        rep1(i, n){
            parent[i] = i;
        }
    }

    int find_ultimate_parent(int n){
        if(parent[n] == n) return n;
        return parent[n] = find_ultimate_parent(parent[n]);
    }

    void union_by_size(int a, int b){
        int ultimate_parent_a = find_ultimate_parent(a);
        int ultimate_parent_b = find_ultimate_parent(b);
        if(ultimate_parent_a == ultimate_parent_b){
            size[ultimate_parent_a]++;
            return;
        }
        if(size[ultimate_parent_a]<size[ultimate_parent_b]){
            parent[ultimate_parent_a] = ultimate_parent_b;
            size[ultimate_parent_b] += size[ultimate_parent_a] + 1;
        }
        else{
            parent[ultimate_parent_b] = ultimate_parent_a;
            size[ultimate_parent_a] += size[ultimate_parent_b] + 1;
        }
    }
};

int solve(vi& a, int n){
    vvi graph = make_graph(a,n);
    int ans = 0;
    vb completed(n+1);
    DisjointSet ds(n);
    int self_loop_count = 0;
    for(int i = 0; i<2*n; i+=2){
        if(a[i] == a[i+1]){
            if(!completed[a[i]]){
                self_loop_count++;
                completed[a[i]] = true;
            }

        }
        ds.union_by_size(a[i], a[i+1]);
        
    }

    map<int ,int> nodes;
    rep1(i, n){
        int cur_ulti_parent = ds.find_ultimate_parent(i);
        // cout<<cur_ulti_parent<<endl;
        nodes[cur_ulti_parent]++;
    }

    for(auto& it: nodes){
        int num_nodes = it.second;
        int edges = ds.size[it.first];
        // cout<<it.first<<" "<<edges<<" "<<it.second<<endl;
        if(edges<num_nodes)  ans++;
        ans += num_nodes;
    }

    
    return ans -self_loop_count;




    
    
    // //handle self loops
    // for(int i = 0; i<2*n; i+=2){
    //     if(a[i] == a[i+1]){
    //         if(!completed[a[i]]){
    //             completed[a[i]] = true;
    //             for(auto& v: graph[a[i]])
    //             dfs(ans, a, graph, n, completed, v);
    //         }
    //     }
    // }
    
    
    // //handle cycles
    // queue<int> q;
    // vi indegree(n+1);
    // for(int i= 0; i<2*n; i+=2){
    //     if(completed[a[i]] or completed[a[i+1]]) continue;
    //     indegree[a[i]]++;
    //     indegree[a[i+1]]++;
    // }

    // rep1(i, n){
    //     if(indegree[i] == 1) q.push(i);
    // }

    // while(!q.empty()){
    //     int u = q.front();
    //     q.pop();
    //     for(auto& v: graph[u]){
    //         indegree[v]--;
    //         if(indegree[v] == 1) q.push(v);
    //     }
    // }
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vi a(2*n);
        rep(i, 2*n) in>>a[i];
        // Your logic here
        cout << solve(a, n) << endl;
    }
    return 0;
}