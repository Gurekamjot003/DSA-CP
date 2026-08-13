#include <bits/stdc++.h>
using namespace std;

class BIT{
    int n;
    vector<int> bit;

public:
    BIT(vector<int>& arr){
        n = arr.size() -1;
        bit.resize(n+1);
        for(int i = 1; i<=n; i++){
            update(i, arr[i]);
        }
        for(auto& n: bit) cout<<n<<" ";
        cout<<endl;
    }

    void update(int id, int val){
        while(id<=n){
            cout<<id<<" ";
            bit[id] += val;
            id += (id & -id);
            
        }
        cout<<endl;
    }

    int query(int id){
        int ans = 0;
        while(id>0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
};
 
int main(){
    vector<int> arr = {0,1, 2, 3, 4, 5};
    BIT bit(arr);
    cout<<bit.query(5)<<endl;
    bit.update(3, 1);
    cout<<bit.query(5)<<endl;
}