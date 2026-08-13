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
#define vvll vector<vector<ll>>

vector<vector<ll>> skibidi_table(ll n, vvll& queries){
    vvll ans(queries.size());
    for(ll i = 0; i<queries.size(); i++){
        auto& query = queries[i];
        if(query[0] == 0){
            ll l_row = 1, r_row = 1ll<<n, l_col = 1, r_col = 1ll<<n;
            ll x = query[1], y = query[2];
            ll left = 1, right= 1ll<<(2*n);
            while(left<right){
                int mid_row = (l_row+r_row)/2;
                int mid_col = (l_col+r_col)/2;
                ll quadrant_size = (right - left + 1ll)/4;
                if(x<=mid_row && y<=mid_col){   // quadrant 1
                    r_row = mid_row;
                    r_col = mid_col;
                }
                else if(x> mid_row && y>mid_col){   //quadrant 4 
                    left += quadrant_size;
                    l_row = mid_row+1;
                    l_col = mid_col+1;
                }
                else if(x> mid_row && y<= mid_col){ // quadrant 3
                    left += quadrant_size*2;
                    l_row = mid_row+1;
                    r_col = mid_col;
                }
                else{    // quadrant 2
                    left+= quadrant_size*3;
                    r_row = mid_row;
                    l_col = mid_col+1;

                }
                right = left+quadrant_size-1;
            }
            ans[i].push_back(left);
        }
        else{
            ll left = 1, right = 1ll<<(2*n);
            ll d = query[1];
            ll l_row = 1, r_row = 1ll<<n, l_col =1, r_col = 1ll<<n;
            while(left<right){
                ll mid_row = (l_row+r_row)/2;
                ll mid_col = (l_col+r_col)/2;
                ll quadrant_size = (right - left + 1ll)/4;
                if(d<(left+quadrant_size)){     //1
                    r_row = mid_row;
                    r_col = mid_col;
                }
                else if(d<(left+quadrant_size*2)){  //4
                    left += quadrant_size;
                    l_row = mid_row+1;
                    l_col = mid_col+1;
                }
                else if(d<(left+quadrant_size*3)){  //3
                    left += quadrant_size*2;
                    l_row = mid_row+1;
                    r_col = mid_col;
                }  
                else{                               //2
                    left+= quadrant_size*3;
                    r_row = mid_row;
                    l_col = mid_col+1;
                }
                right = left+quadrant_size-1;
            }
            ans[i].push_back(l_row);
            ans[i].push_back(l_col);
        }
    }
    return ans;
}

int main(){
    // ifstream in("input string.txt");
    int t; cin>>t;
    while(t--){
        ll n, q; 
        cin>>n>>q;
        vector<vector<ll>> queries(q);
        for(int i = 0; i<q; i++){
            string temp;
            cin>>temp;
            if(temp == "->"){
                queries[i].push_back(0);
                ll x, y; 
                cin>>x>>y;
                queries[i].push_back(x);
                queries[i].push_back(y);
            }
            else{
                queries[i].push_back(1);
                ll d;
                cin>>d;
                queries[i].push_back(d);
            }
        }

        vvll ans = skibidi_table(n, queries);
        for(auto& n: ans){
            for(auto& m: n) cout<<m<< " ";
            cout<<endl;
        }
    }
    // int t; cin>>t;
    // while(t--){
    // 	int n; cin>>n;
    // }
     return 0;
}