#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(cost1+cost2 >= costBoth){
            long long count =  min(need1, need2);
            ans += count*costBoth;
            need1 -= count;
            need2 -= count;
        }
        return ans + 1ll*min(cost1, costBoth)*need1 + 1ll*min(cost2, costBoth)*need2;
    }
};