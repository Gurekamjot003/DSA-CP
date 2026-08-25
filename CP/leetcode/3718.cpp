#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> freq(nums.begin(), nums.end());
        for(int i = 1; i<=nums.size()+1; i++){
            if(!freq.count(i*k)) return i*k;
        }
        return -1;
    }
};