#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dir = 0, count = 1, ans = 1;
        for(int i = 1; i<nums.size(); i++){
            int new_dir = nums[i]-nums[i-1];
            if(new_dir) new_dir/=abs(new_dir);
            if(new_dir == 0) count = 1;
            else if(dir == new_dir) count++;
            else{
                dir = new_dir;
                count = 2;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};