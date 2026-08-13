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
#define all(x) x.begin(), x.end()
#define yn(x) cout << (x ? "YES" : "NO") << endl
#define endl "\n"

int mod;

vvi product(vvi &matrix1, vvi& matrix2)
{
    int a = matrix1.size(), b = matrix2.size(), c = matrix2[0].size();
    vvi ans(a, vector<int>(c));
    for (int k = 0; k < b; k++)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = (ans[i][j] + 1ll * matrix1[i][k] * matrix2[k][j]) % mod;
            }
        }
    }
    return ans;
}

vvi identity(int n){
    vvi I(n , vi(n));
    for(int i = 0; i<n; i++) I[i][i] = 1;
    return I;
}

vvi matrix_exp(vvi &matrix, int exp)
{
    int n = matrix.size();
    vvi ans = identity(n);

    while (exp)
    {
        if (exp & 1)
            ans = product(ans, matrix);
        matrix = product(matrix, matrix);
        exp >>= 1;
    }
    return ans;
}

int final_matrix_sum(vvi& init_matrix, vvi& T, int n){
    T = matrix_exp(T, n);
    vvi final_matrix = product(T, init_matrix);
    int ans = 0;
    for(int i = 0; i<final_matrix.size(); i++){
        ans = (ans + final_matrix[i][0])%mod;
    }
    return ans;
}