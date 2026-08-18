#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size() == k) return *max_element(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for(auto& n: nums) freq[n]++;
        int ans = -1;
        if(k == 1){
            for(auto&n: nums) if(freq[n] == 1) ans = max(ans, n);
        } 
        else{
            if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
            if(freq[nums.back()] == 1) ans = max(ans, nums.back());
        }  
        return ans;
    }
};