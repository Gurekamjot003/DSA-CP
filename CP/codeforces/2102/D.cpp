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

// Function to get input stream based on file availability
istream& getInputStream() {
    static ifstream file("input.txt");
    return (file.is_open()? file: cin);
}

vi solve(vi& arr, int n){
    vi index(n+1);
    vi odd_indexed_values, even_indexed_values;
    for(int i = 0; i<n; i++){
        index[arr[i]] = i;
        if(i%2) even_indexed_values.push_back(arr[i]);
        else odd_indexed_values.push_back(arr[i]);
    }
    sort(all(even_indexed_values));
    sort(all(odd_indexed_values));
    int odd_ptr = 0, even_ptr = 0;
    for(int i = 0; i<(n-3); i++){
        if(i%2){    // for even
            int ind = index[even_indexed_values[even_ptr]];
            if(ind == (n-1)){// last index
                swap(index[arr[ind]], index[arr[ind-2]]);
                swap(index[arr[ind-1]], index[arr[ind-3]]);
                swap(arr[ind], arr[ind-2]);
                swap(arr[ind-1], arr[ind-3]);
                // for(auto& n: arr) cout<<n<<" ";
                // cout<<endl;
            }
            ind = index[even_indexed_values[even_ptr]];
            swap(index[arr[ind]], index[arr[i]]);
            swap(index[arr[ind+1]], index[arr[i+1]]);
            swap(arr[ind], arr[i]);
            swap(arr[ind+1], arr[i+1]);
            even_ptr++;
        } 
        else{
            int ind = index[odd_indexed_values[odd_ptr]];
            if(ind == (n-1)){// last index
                swap(index[arr[ind]], index[arr[ind-2]]);
                swap(index[arr[ind-1]], index[arr[ind-3]]);
                swap(arr[ind], arr[ind-2]);
                swap(arr[ind-1], arr[ind-3]);
                // for(auto& n: arr) cout<<n<<" ";
                // cout<<endl;
            }
            ind = index[odd_indexed_values[odd_ptr]];
            swap(index[arr[ind]], index[arr[i]]);
            swap(index[arr[ind+1]], index[arr[i+1]]);
            swap(arr[ind], arr[i]);
            swap(arr[ind+1], arr[i+1]);
            odd_ptr++;
        }
        // for(auto& n: arr) cout<<n<<" ";
        // cout<<endl;
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    istream& in = getInputStream();
    int t; in >> t;
    while (t--) {
        int n; in >> n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        // Your function call here
        vi ans = solve(a, n);
        for(auto& n: ans) cout<<n<<" "; 
        // cout<<endl<<"____________________________________";
        cout<<endl;
        // cout << program_name(parameters) << endl;
    }

    return 0;
}