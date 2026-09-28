#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> start(n, -1);
        int left = 0, cur = 0;
        for(int i = 0; i<arr.size(); i++){
            cur+= arr[i];
            while(left<=i && cur>target) cur-=arr[left++];
            if(cur == target) start[i] = left;
        }

       
        vector<int> min_at_right(n+1, INT_MAX);
        int min_val = INT_MAX;
        int ans = INT_MAX;
        for(int i = n-1; i>=0; i--){
            min_val = min(min_val, min_at_right[i+1]);
            if(start[i] != -1){
                int cur_val = i-start[i]+1;
                if(min_val != INT_MAX) ans = min(ans, min_val + cur_val);
                min_at_right[start[i]] = cur_val;
               
            }

        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};