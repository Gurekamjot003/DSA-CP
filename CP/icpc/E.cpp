#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define nline '\n'
#define sp ' '
#define no "NO\n"
#define yes "YES\n"

const int MOD = 998244353;
const int N = 200003;
vector<long long> fact, invFact;

template <typename T>
vector<T> readArray(int n, int type = 0)
{
    vector<T> arr(n + type);
    for (int i = 0 + type; i < n + type; i++)
        cin >> arr[i];
    return arr;
}

template <typename T>
void printArray(int left, int right, vector<T> &arr)
{
    for (int i = left; i < right; i++)
        cout << arr[i] << sp;
    cout << endl;
}

long long FastExponentiation(long long base, long long exponent, long long mod = MOD)
{
    long long res = 1;
    base %= mod;
    while (exponent > 0)
    {
        if (exponent & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return res;
}

void getFactorial(int n, vector<long long> &factorial)
{
    factorial.resize(n);
    factorial[0] = 1;
    for (int i = 1; i < n; i++)
        factorial[i] = (1LL * i * factorial[i - 1]) % MOD;
}

void getInverseFactorial(int n, vector<long long> &factorial, vector<long long> &inverseFactorial)
{
    inverseFactorial.resize(n);
    inverseFactorial[n - 1] = FastExponentiation(factorial[n - 1], MOD - 2);
    for (int i = n - 2; i >= 0; i--)
        inverseFactorial[i] = ((i + 1LL) * inverseFactorial[i + 1]) % MOD;
}

long long nCr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void dfs(int curr, int par, int depth, int c, vector<int> &below, vector<ll> &poss, vector<vector<int>> &adj)
{
    poss[curr] = nCr(depth - 1, c - 1);
    for (int child : adj[curr])
    {
        if (child == par)
            continue;
        dfs(child, curr, depth + 1, c, below, poss, adj);
        below[curr] += below[child] + 1;
    }
}

long long get_fact(int x)
{
    return x < 0 ? 0LL : fact[x];
}

void btk(int n, vector<vector<int>> edges, vector<bool> &used, vector<vector<vector<int>>> &edges_perm, int i = 0)
{
    if (i == n - 1)
    {
        edges_perm.push_back(edges);
        return;
    }
    for (int j = 1; j < n; j++)
    {
        if (used[j])
            continue;
        edges[i].push_back(j);
        used[j] = true;
        btk(n, edges, used, edges_perm, i + 1);
        used[j] = false;
        edges[i].pop_back();
    }
}

void search(vector<vector<pair<int, int>>> &graph, int &x, int u = 1, int parent = -1)
{
    int og_x = x;
    // cout<<1<<endl;
    for (auto &[v, p] : graph[u])
    {
        if (v == parent)
            continue;
        if (p == x)
            x++;
        search(graph, x, v, u);

        if (x != og_x)
            return;
    }
}

ll brute(int n, int c, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> edges_perm;
    vector<bool> used(n);
    btk(n, edges, used, edges_perm);
    // cout << edges_perm.size() << endl;
    
    ll ans = 0;
    int perm = 0;
    for (auto &edges : edges_perm)
    {
        vector<vector<pair<int, int>>> graph(n + 1);
        // cout<<"Perm: "<<++perm<<endl;
        // cout<<"All edges:"<<endl;
        for (auto &e : edges)
        {
            // cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        // cout << 1 << endl;
        int x = 1;
        search(graph, x);
        if (x == c+1)
            ans = (ans + 1) % MOD;
    }
    return ans;
}

ll solve(int n, int c, vector<vector<int>> &edges)
{

    long long res = 0;
    vector<ll> poss(n + 1, 0);
    vector<int> below(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (auto &e : edges)
    {

        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    dfs(1, 0, 0, c, below, poss, adj);

    for (int i = 1; i <= n; i++)
    {
        res = (res + (poss[i] * ((((get_fact(n - 1 - c) - ((1LL * below[i] * get_fact(n - 2 - c)) % MOD)) % MOD + MOD)) % MOD)) % MOD) % MOD;
    }
    return res;
}

int get_random(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

void judge()
{
    srand(0);
    int t = 10;
    while (t--)
    {

        int n = 10; 
        int c = get_random(1, n / 2);
        // cout << n << " " << c << endl;
        vector<vector<int>> edges;
        while (true)
        {
            vector<vector<int>> temp(n - 1, vector<int>(2));
            for (int i = 0; i < n - 1; i++)
            {
                temp[i][0] = get_random(1, n - 1);
                temp[i][1] = get_random(temp[i][0] + 1, n);
            }

            vector<vector<int>> graph(n + 1);
            for (auto &e : temp)
            {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }
            int count = 0;
            vector<bool> visited(n + 1);
            queue<int> q;
            q.push(1);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (visited[u])
                    continue;
                visited[u] = true;
                count++;
                for (auto &v : graph[u])
                    q.push(v);
            }

            if (count == n)
            {
                edges = temp;
                break;
            }
        }

        ll correct_ans = brute(n, c, edges), my_ans = solve(n, c, edges);
        if ( my_ans != correct_ans)
        {

            cout << "Correct ans: " << correct_ans << endl;
            cout << "Your ans: " << my_ans << endl;

            cout << "n: " << n << endl;
            cout << "c: " << c << endl;
            cout << "Edges:" << endl;
            for (auto &e : edges)
                cout << e[0] << " " << e[1] << endl;
            cout << endl;
            return;
        }
        // cout << 1 << endl;
    }
    cout << "All testcases passed" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getFactorial(N, fact);
    getInverseFactorial(N, fact, invFact);

    judge();
    // int t = 1;
    // cin >> t;
    // while (t--)
    // {
    //     int n, c;
    //     cin >> n >> c;
    //     vector<vector<int>> edges(n - 1, vector<int>(2));
    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         cin >> edges[i][0] >> edges[i][1];
    //     }

    //     // cout<<solve(n, c, edges) <<endl;
    //     cout << brute(n, c, edges) << endl;
    // }

    return 0;
}