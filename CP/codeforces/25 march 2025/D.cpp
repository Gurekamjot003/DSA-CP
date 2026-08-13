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

int place_of_the_olympiad(int n, int m, int k){
    int left = 1, right = m;
    int ans = right;
    while(left<=right){
        int mid = (left+right)/2;
        int vacancies = m/(mid + 1);
        int occupied_per_row = m - vacancies;
        ll total_occupation = occupied_per_row*n;
        if(total_occupation >=k){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return ans;
}

int main(){
    ifstream in("input string.txt");
    int t; in>>t;
    while(t--){
        int n, m, k; 
        in>>n>>m>>k;
        
        cout<<place_of_the_olympiad(n, m, k)<<endl;
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}