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

int xor_triangle(int x){
    // if(x<=4) return false;
    int y = x;
    int i  = 0;
    while(i<32 && ((1<<i) & x)) i++; //skip righmost ones
    // cout<<i<<" ";
    //convert zeroes to ones until one comes
    bool ans_found = false;
    while(i<31){
        y ^= (1<<i);
        if(1<<i & x){
            ans_found = true;
            break;
        }
        i++;
    }
    int z = x^y;
    // cout<<z<<" ";
    if(!ans_found) return -1;
    if((x+y) <= z or (y+z)<=x or (x+z) <=y) return -1;
    return y;

    

}

int main(){
    // ifstream in("input string.txt");
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        
        cout<<xor_triangle(x)<<endl;
    }
    // ifstream in("input string.txt");
    // int t; in>>t;
    // while(t--){
    //     int x; in>>x;
        
    //     cout<<xor_triangle(x)<<endl;
    // }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}