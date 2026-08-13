// used when we have to find max/min of all subarrays 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int n =heights.size();
        int ans = 0;
        for(int i=  0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int to_check = st.top(); st.pop();
                int left = (st.empty()? 0: st.top()+1);
                ans = max(ans, heights[to_check]*(i - left));
            }
            st.push(i);
        }
        while(!st.empty()){
            int to_check = st.top(); st.pop();
            int left = (st.empty()? 0: st.top()+1);
            ans = max(ans, heights[to_check]*(n-left));
        }
        return ans;

    }
};