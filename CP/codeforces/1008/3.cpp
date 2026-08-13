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
#define uset unordered_set

void add_swap(int i, int ans, vll& arr){
    swap(arr[i*2], arr[i*2+1]);
    arr.insert(arr.begin(), ans);
}

vll Breach_of_faith(vll& arr){
    uset<ll> present(arr.begin(), arr.end());
    long long ans = 0;
    sort(arr.rbegin(), arr.rend());
    vll differences_array(arr.size()/2);
    for(int i = 0; i<arr.size(); i+=2){
        differences_array.push_back(arr[i] - arr[i+1]);
        ans += differences_array.back();
    }
    if(present.find(ans) == present.end()){
        arr.insert(arr.begin(), ans);
        return arr;
    }
    // sort(differences_array.begin(), differences_array.end());
    for(int i = 0; i<differences_array.size(); i++){
        ans -= 2*differences_array[i];
        if(present.find(ans) == present.end()){
            swap(arr[i*2], arr[i*2+1]);
            arr.insert(arr.begin(), ans);
            return arr;
        }
        ans += 2*differences_array[i];
    }
    arr.insert(arr.begin(), ans);
    return arr;
}

int main(){
    // ifstream in("input string.txt");
    // int t; in>>t;
    // while(t--){
    //     int n; in>>n;
    //     vll arr(2*n);
    //     for(int i = 0; i<arr.size(); i++) in>>arr[i];
    //     vll ans = Breach_of_faith(arr);
    //     for(auto n: ans) cout<<n<<" ";
    //     cout<<endl;
    //     // cout<<program_name(parameters)<<endl;
    // }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vll arr(2*n);
        for(int i = 0; i<arr.size(); i++) cin>>arr[i];
        vll ans = Breach_of_faith(arr);
        for(auto n: ans) cout<<n<<" ";
        cout<<endl;
        // cout<<program_name(parameters)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}