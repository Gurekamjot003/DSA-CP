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

long long no_of_zero_position(int x, long long k, string& movements){
    long long ans = 0;
    int ptr = 0;
    long long cur_time = 0;
    long long cur_position = x;
    while(cur_time<k && cur_position != 0 && ptr<movements.size()){
        movements[ptr++] == 'L'? cur_position--: cur_position++;
        cur_time++;
    }
    if(cur_position == 0){
        ans++;
        ptr = 0;
    }
    if(cur_time == k or ptr == movements.size()) return ans;
    
    k-=cur_time;
    cur_time = 1;
    ptr = 1;
    movements[0] == 'L'? cur_position--: cur_position++;
    while(cur_time<k && cur_position != 0 && ptr<movements.size()){
        movements[ptr++] == 'L'? cur_position--: cur_position++;
        cur_time++;
    }
    if(cur_position == 0) ans+=(k/cur_time);
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, x;
        long long k;
        cin>>n>>x>>k;
        string movements;
        cin>>movements;
        cout<<no_of_zero_position(x, k, movements)<<endl;
    }
    return 0;
}