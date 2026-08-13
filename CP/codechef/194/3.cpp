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

int solve(vi& a, int n){
    sort(all(a));
    reverse(all(a));
    int i = a[0], j = a[1], k = a[2];
    int ans = 0;
    amax(ans, i%(j+k));
    amax(ans, j%(i+k));
    amax(ans, k%(i+j));

    reverse(all(a));
    for(int i = 0; i<(n-1); i++){
        for(int j = 0; j<(n-1); j++){
            if(i == j) continue;
            amax(ans, a.back()%(a[i] + a[j]));
        }
    }
    return ans;
}

// vector<int> arr(100);
// vector<int> current;
// int count_combinations = 0;

// // Backtracking function to select 3 values
// void backtrack(int index, int& ans) {
//     if (current.size() == 3) {
//         // Process the combination
//         count_combinations++;
//         // Uncomment below to see the combinations (comment for stress testing)
//         // for (int num : current) cout << num << " ";
        
//         amax(ans, current[0]%(current[1]+ current[2]));
//         amax(ans, current[1]%(current[0] + current[2]));
//         amax(ans, current[2]%(current[0]+current[1]));

//         // cout << "\n";
//         return;
//     }

//     if (index >= arr.size()) return;

    
//     // Include current index
//     current.push_back(arr[index]);
//     backtrack(index + 1, ans);
//     current.pop_back();

//     // Exclude current index
//     backtrack(index + 1, ans);
// }

// void stress_test(){
//     srand(time(0));

//     // Generate random array of 100 integers between 1 and 1000
//     arr = {1, 2, 3,3, 3, 24};
//     int brute_force =0;
//     // Start backtracking
//     backtrack(0, brute_force);

//     if(brute_force != solve(arr, arr.size())){

//         cerr<<"Arr = ";
//         rep(i, arr.size()) cerr<<arr[i]<<" ";
//         cout<<endl;
//         cerr<<"Correct = "<<brute_force<<endl;
//         cerr<<"Output = "<<solve(arr, arr.size())<<endl;
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    //  stress_test();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vi a(n);
        rep(i,n) in>>a[i];
        cout << solve(a, n) << endl;
    }
    return 0;
}