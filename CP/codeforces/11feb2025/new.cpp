#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int start, int end, int maxval){
    int total_sum = 0;
    for(int i = start; i<=end; i++){
        total_sum += arr[i];
    }
    int left = start, right = start+1;
    unordered_map<int, int> mp;
    if(arr[start] < maxval) mp[arr[start]]++;
    int ans = total_sum;
    int cursum = arr[start];
    for(; right<=end; right++){
        while(mp.size() == (maxval) && left<right){
            ans = min(ans, cursum);
            if(arr[left] < maxval){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0) mp.erase(arr[left]);
            }
            cursum -= arr[left];
            left++;
            
        }
        if(arr[right] < maxval){
            mp[arr[right]]++;
        }
        cursum += arr[right];
    }
    while(mp.size() == (maxval) && left<right){
        ans = min(ans, cursum);
        if(arr[left] < maxval){
            mp[arr[left]]--;
            if(mp[arr[left]] == 0) mp.erase(arr[left]);
        }
        cursum -= arr[left];
        left++;
        
    }
    return ans;
    
    
}

pair<int, int> min_max_sum(vector<int>& arr){
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    int cur = 0;
    // for(auto& n: sorted_arr) cout<<n<<" ";
    // cout<<endl;
    int min_pos_value_not_in_array = sorted_arr.back()+1;
    for(int i = 0; i<sorted_arr.size(); i++){
        if(sorted_arr[i] > cur){
            min_pos_value_not_in_array = cur;
            break;
        }
        cur = sorted_arr[i]+1;
    }
    // cout<<min_pos_value_not_in_array<<endl;
    unordered_map<int, int> mp1, mp2, mp3;
    int windowsum = 0, total_sum = accumulate(arr.begin(), arr.end(), 0);
    for(int i = 1; i<arr.size()-1; i++){
        if(arr[i]<min_pos_value_not_in_array) mp2[arr[i]]++;
        windowsum += arr[i];
    }
    if(arr[0]<min_pos_value_not_in_array) mp1[arr[0]]++;
    if(arr.back()<min_pos_value_not_in_array) mp3[arr.back()]++;
    int left = 1, right = arr.size()-2;
    while(left<right && mp1.size()<(min_pos_value_not_in_array)){
        // cout<<left<<" "<<right<<endl;
        if(arr[left] < min_pos_value_not_in_array){
            mp1[arr[left]]++;
            mp2[arr[left]]--;
            if(mp2[arr[left]] == 0) return {-1, -1};
        }
        windowsum -= arr[left];
        left++;
    }
    // cout<<endl;
    while(left<right && mp3.size()<(min_pos_value_not_in_array)){
        // cout<<left<<" "<<right<<endl;
        if(arr[right] < min_pos_value_not_in_array){
            mp3[arr[right]]++;
            mp2[arr[right]]--;
            if(mp2[arr[right]] == 0) return {-1, -1};
        }
        windowsum -= arr[right];
        right--;
    }
    // cout<<windowsum<<endl;
    int minval = total_sum - 2*windowsum;
    int maxval = minval;
    // now we have to find minimum windowsum from left to right in the arr
    maxval = total_sum - 2*solve(arr, left, right, min_pos_value_not_in_array);
    return {minval, maxval};
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    vector<int> arr(n);
	    for(int i = 0; i<n; i++){
	        cin>>arr[i];
	    }
	    auto ans = min_max_sum(arr);
	    cout<<ans.first<<" "<<ans.second<<endl;
	}

}
