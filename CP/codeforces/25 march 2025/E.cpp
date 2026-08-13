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

vector<bool> sieve(10000001, 1);
vector<int> primes = {1};

ll interesting_ratio(int n){
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        int left = 0, right = primes.size()-1;
        int index = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if((1ll*primes[mid]*i) <=n){
                index = mid;
                left = mid+1;
            }
            else right= mid-1;
        }
        // cout<<index<<" "<<i<<endl;
        if(index == 0) break;
        ans += (index);
    }
    return ans;
}


int main(){
    ifstream in("input string.txt");
    for(int i = 2; i<sieve.size(); i++){
        if(!sieve[i]) continue;
        primes.push_back(i);
        for(int cur = i*2; cur<sieve.size(); cur+= i) sieve[cur] = false;
    }
    // for(int i = 0; i<100; i++) cout<<primes[i]<< " ";
    // cout<<endl;

    int t; in>>t;
    while(t--){
        int n; in>>n;
        
        // interesting_ratio(n);
        cout<<interesting_ratio(n)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}