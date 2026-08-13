#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
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

int fizzBuzz(int n){
    int multiples_of_15 = n/15;
    n%=15;
    int ans = 0;
    n<3? ans+=(n+1): ans+=3;
    ans+=multiples_of_15*3;
    return ans;

}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<fizzBuzz(n)<<endl;
        
    }
    return 0;
}