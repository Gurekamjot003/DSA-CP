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

bool(is_possible(string& req, vi& penalties, int& k, int& max_penalty)){
    int count = 0;
    char cur_color = 'R';
    for(int i = 0; i<penalties.size(); i++){
        if(req[i] != cur_color && penalties[i] > max_penalty){
            if(cur_color == 'R'){
                count++;
                cur_color = 'B';
            }
            else cur_color = 'R';
            // cout<<i<<" "<<cur_color<<endl;
        }
    }
    // cout<<count<<" "<<k<<" "<<max_penalty<<endl;
    return count<=k;
}

int maximum_penalty(int k, string& req, vi& penalties){
    int left = 0, right = *max_element(penalties.begin(), penalties.end());
    int ans = right;
    while(left<=right){
        int mid = (left+right)/2;
        if(is_possible(req, penalties, k, mid)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string req;
        cin>>req;
        vi a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        cout<<maximum_penalty(k, req, a)<<endl;
    }
    return 0;
}