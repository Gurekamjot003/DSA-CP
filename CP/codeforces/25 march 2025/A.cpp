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

int olympiad_date(vi &arr)
{
    vi freq(10);
    int total_zeros = 0;
    string date = "01.03.2025";
    for (auto &ch : date)
    {
        if (isdigit(ch))
            freq[ch - '0']++;
    }
    // for(auto n: freq) cout<<n<< " ";
    for (auto &n : freq)
        if (n == 0)
            total_zeros++;
    for(int i = 0; i<arr.size(); i++){
        freq[arr[i]]--;
        if(freq[arr[i]] == 0) total_zeros++;
        if(total_zeros == freq.size()) return i+1;
    }
    return 0;
}

int main()
{
    ifstream in("input string.txt");

    int t;
    in >> t;

    while (t--)
    {

        int n;
        in >> n;

        vi a(n);
        for (int i = 0; i < n; i++)
            in >> a[i];
        cout << olympiad_date(a) << endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
    return 0;
}