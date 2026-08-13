#include <bits/stdc++.h>
using namespace std;

// Macros
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
#define v vector
#define all(x) x.begin(),x.end()
#define yn(x) cout<<(x?"YES":"NO")<<endl
#define endl "\n"

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

int n;

// Function to get input stream based on file availability
istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}

void toggle(int n){
    cout<<"? 2 "<<n<<endl<<flush;
}

int get_val(vi arr){
    cout<<"? 1 "<<arr.size()<<" ";
    for(auto& n: arr){
        cout<<n<<" ";
    }
    cout<<endl<<flush;
    int ans;
    cin>>ans;
    return ans;
}

int find_centroid(vvi& graph){
    vi indegree(n+1);
    queue<int> q;
    for(int i = 1; i<=n; i++){
        indegree[i] = graph[i].size();
        if(indegree[i] == 1){
            q.push(i);
        }
    }
    int remaining = n;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        indegree[node]--;
        for(auto& neighbor: graph[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 1) q.push(neighbor);
        }
        remaining--;
        if(remaining <=2) break;
    }
    return q.front();
}

int find_root_node(vvi& graph, int node){
    vi& neighbors = graph[node];
    int left = 0, right = neighbors.size()-1;
    while(left<right){
        int mid = (left+right)/2;
        int left_half_old_val = get_val(vi(neighbors.begin(), neighbors.begin() + mid));
        int right_half_old_val = get_val(vi(neighbors.begin()+mid, neighbors.end()));
        toggle(node);
        int left_half_new_val = get_val(vi(neighbors.begin() + left, neighbors.begin() + mid));
        int right_half_new_val = get_val(vi(neighbors.begin()+mid, neighbors.begin() + right));
        int abs_left_diff = abs(left_half_old_val - left_half_new_val);
        int abs_right_diff = abs(right_half_old_val - right_half_new_val);
        // both have no difference then node is the root itself
        if(abs_left_diff == abs_right_diff) return node;    
        if(abs_left_diff < abs_right_diff) right = mid-1;
        else left = mid+1;
    }
    // here left = right
    
    return find_root_node(graph, neighbors[left]);
}

vi interaction(vvi& graph){
    int centroid = find_centroid(graph);
    int root = find_root_node(graph, centroid);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vvi graph(n+1);
        for(int i = 1; i<n; i++){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v); 
            graph[v].push_back(u); 
        }
        // Your function call here
        vi ans =  interaction(graph);
        cout<<"! ";
        for(int i = 1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<endl<<flush;
    }

    return 0;
}