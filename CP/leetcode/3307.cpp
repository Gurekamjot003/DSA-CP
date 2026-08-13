#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

class Solution {

public:
    char kthCharacter(long long k, vector<int>& operations) {
        int idx = min(60, (int)operations.size()-1);
        ll cur_num = 1ll<<(idx+1);
        int ans = 0;
        while(idx>=0){
            ll mid = cur_num/2;
            if(k>mid){
                if(operations[idx] == 1) ans ++;
                k-=mid;
            }
            idx--;
            cur_num = mid;
        }
        return ans%26 + 'a';
    }
};

