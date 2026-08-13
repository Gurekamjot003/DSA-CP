/*
nums - whole array whose elements are to be categorized
a - prime indices only
b - non prime indices

sum_a - sum of all elements of a
sum_b - sum of all elements of b

return absolute diff bw sums 

nums = {-1, 5, 7, 0};
sum_a = 7 + 0 =7 
sum_b = 4
return 3

nums = {2, 3, 4}
sum_a = 4 
sum_b = 5
return 1

*/


#include<bits/stdc++.h>
using namespace std;

bool calculate_prime_or_not(int n){
    if(n<2) return false;
    for(int i = 2; (i*i)<=(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

int find_absolute_difference(vector<int>& nums){
    int sum_a = 0, sum_b = 0;

    for(int i= 0; i<nums.size(); i++){
        if(calculate_prime_or_not(i)) sum_a += nums[i];
        else sum_b += nums[i];
    }

    return abs(sum_a - sum_b);
}

int main(){
    vector<int> nums = {-1, 5, 7, 0};
    cout<<find_absolute_difference(nums);
    return 0;
}