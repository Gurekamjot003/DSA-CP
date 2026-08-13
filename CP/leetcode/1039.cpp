#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    long long solve(vector<int>& values, int left, int right){
        // cout<<left<<" "<<right<<" "<<n<<endl;
        int diff = (right - left + 1);
        if(diff<=2) return 0;
        if(diff == 3){
            long long prod = 1;
            int ptr = left;
            do{
                prod*=values[ptr%n];
            }while((ptr++)!=right);
            return prod;
        }

        long long ans = INT64_MAX;
        for(int k = left+2; k<(right - 1); k++){
            int idx = k%n;
            long long l = solve(values, left, k);
            long long r = solve(values, k, right);
            ans = min(ans, l+r);
        }

        return ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        n = values.size();
        return solve(values, 0, 6);
    }
};

int main(){
    vector<int> values = {1,3,1,4,1,5};
    Solution sol;
    cout<<sol.minScoreTriangulation(values);

}