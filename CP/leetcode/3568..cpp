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

class Solution {
    // 3D Array: visited[i][j][mask] stores the MAXIMUM energy we've had at this state.
    // Size: 20 * 20 * 1024 * 4 bytes = ~1.6 MB (Much faster to memset!)
    int max_energy_at[20][20][1024]; 
    
    // Using a struct avoids heap allocations entirely (lightning fast)
    struct State {
        int i, j, energy, mask;
    };

public:
    int minMoves(vector<string>& classroom, int energy) {
        // Initialize with -1 (meaning unvisited / impossible energy)
        memset(max_energy_at, -1, sizeof(max_energy_at));
        
        int n = classroom.size(), m = classroom[0].size();
        int max_energy = energy;
        int start_i = 0, start_j = 0;
        
        vvi litter_val(n, vi(m, -1));
        int l_val = 0;
        
        // Setup Grid
        rep(i, n) {
            rep(j, m) {
                if (classroom[i][j] == 'S') {
                    start_i = i; start_j = j;
                }
                if (classroom[i][j] == 'L') {
                    litter_val[i][j] = l_val++;
                }
            }
        }
        
        int target_mask = (1 << l_val) - 1;
        
        // Edge case: No litter to collect at all
        if (target_mask == 0) return 0;
        
        queue<State> q;
        q.push({start_i, start_j, max_energy, 0});
        max_energy_at[start_i][start_j][0] = max_energy;
        
        int cur_steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j, cur_energy, mask] = q.front();
                q.pop();
                
                // 1. Process current cell effects FIRST
                if (classroom[i][j] == 'R') {
                    cur_energy = max_energy;
                } else if (classroom[i][j] == 'L') {
                    mask |= (1 << litter_val[i][j]);
                }
                
                // 2. Check if we've collected everything immediately after updating the mask
                if (mask == target_mask) {
                    return cur_steps;
                }
                
                // 3. Explore neighbors
                int di = 0, dj = 1;
                rep(t, 4) {
                    int ni = i + di, nj = j + dj;
                    
                    // Direction trick logic
                    swap(di, dj);
                    dj = -dj;
                    
                    // Boundary and Obstacle checks
                    if (ni < 0 || nj < 0 || ni == n || nj == m || classroom[ni][nj] == 'X') continue;
                    
                    int next_energy = cur_energy - 1; // Move costs 1 energy
                    
                    // Valid move check & check if this is the highest energy path to this state
                    if (next_energy >= 0 && max_energy_at[ni][nj][mask] < next_energy) {
                        max_energy_at[ni][nj][mask] = next_energy;
                        q.push({ni, nj, next_energy, mask});
                    }
                }
            }
            cur_steps++;
        }
        
        return -1;
    }
};