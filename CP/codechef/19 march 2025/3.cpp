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

bool check(vi& arr, int ind){
    int temp = arr[ind];
    arr.erase(arr.begin() + ind);
    int prev_diff = 0;
    bool ans = true;
    for(int i = 1; i<arr.size(); i++){
        if((arr[i] - arr[i-1]) <= prev_diff) ans = false;
        prev_diff = arr[i] - arr[i-1];
    }
    arr.insert(arr.begin() + ind, temp);
    return ans;
}

string smoothly_increasing(vi & arr){
    string ans;
    int flag = -1;
    int prev_diff = 0;
    for(int i = 1; i<arr.size(); i++){
        if((arr[i] - arr[i-1]) <= prev_diff){
            if(flag != -1){
                while(ans.size() < arr.size()) ans.push_back('0');
                return ans;
            }
            flag = i;
        }
        prev_diff = arr[i] - arr[i-1];
    }
    if(flag == -1){
        while(ans.size() < arr.size()) ans.push_back('1');
        return ans;
    }
    for(int i = 0; i<(flag-2); i++){
        ans.push_back('0');
    }
    for(int i = max(0, flag-2); i<min(flag+3, (int)arr.size()); i++){
        ans.push_back(check(arr, i)? '1': '0');
    }
    while(ans.size() <arr.size()) ans.push_back('0');
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n; in>>n;
        vi a(n);
        for(int i = 0; i<n; i++) in>>a[i];
        cout<<smoothly_increasing(a)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}