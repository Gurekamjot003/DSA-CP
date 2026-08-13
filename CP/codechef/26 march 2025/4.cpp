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

vi station_allocation(vi& capacities, vvi& queries){
    sort(capacities.begin(), capacities.end());
    ll total_sum = accumulate(capacities.begin(), capacities.end(), 0ll);
    vi ans;
    for(auto& query: queries){
        ll x = query[0], y= query[1];
        int index = lower_bound(capacities.begin(), capacities.end(), x) - capacities.begin();
        ll cur = 0;
        
        ll alternate = INT64_MAX;
        if(index == capacities.size()){
            index--;
            cur = (x - capacities.back());
        }
        else if(capacities[index] > x && index != 0){
            int alt_index = index -1;
            
            ll cur = x-capacities[alt_index];
            ll alt_capacity = total_sum - capacities[alt_index];
            alternate =  cur + max(0ll, y - alt_capacity);

        }
        ll capacity_avail_for_storage = total_sum - capacities[index];
        ll y_tokens = max(0ll, y-capacity_avail_for_storage);
        ans.push_back(min(cur + max(0ll, y-capacity_avail_for_storage), alternate));
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi c(n);
        for(int i = 0; i<n; i++) in>>c[i];
        int q; in>>q;
        vector<vector<int>> queries;
        while(q--){
            int x, y;
            in>>x>>y;
            queries.push_back({x, y});
        }
        vi ans = station_allocation(c, queries);
        for(auto& n: ans) cout<<n<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}