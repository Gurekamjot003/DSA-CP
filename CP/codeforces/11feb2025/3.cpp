#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define pll pair<ll, ll>
#define vll vector<ll>
#define vb vector<bool>
#define umapii unordered_map<int, int>
#define mapii map<int, int>
#define useti unordered_set<int>

int solve(vi digits, int i){
    int ans = 0;
    while(digits[i] != 7){
        digits[i]++;
        if(digits[0]){
            digits[0]--;
            if(digits[0] == 7) return ans+1;
        }
        else{
            digits[0] = 9;
            digits[i]--;
        }
        if(digits[i] >9){
            int cur = i;
            while(digits[cur]>9){
                digits[cur] = 0;
                digits[cur+1]++;
                cur++;
            }
            digits[cur]++;
            if(digits[cur] == 7) return ans+1;
        }
        ans++;
        // for(auto n: digits) cout<<n<<" ";
        // cout<<ans;
        // cout<<endl;
        // if(ans>10) return INT_MAX;
    }
    return ans;
}

int numOperations(int n){
    vi digits;
    int temp = n;
    while(temp){
        int lastdig = temp%10;
        digits.push_back(lastdig);
        temp/=10;
    }
    digits.push_back(0);
    int ans = INT_MAX;
    if(digits[0]>7) ans = digits[0]-7;
    else ans = digits[0]-7 + 10;
    for(int i = 1; i<digits.size(); i++){
        int cur = 7-digits[i];
        if(cur>digits[0]) cur++;
        ans = min(ans, cur);
        if(digits[i]>7){
            cur = digits[i] - 8;
            cur *= pow(10, i);
            if(cur>ans) continue;
            for(int j = i-1; j>=0; j--){
                cur += digits[j] * pow(10, j);
            }
            cur++;
            ans = min(ans, cur);
        }
        
    }
    return ans;
}


int main(){
    int t; cin>>t; 
    while(t--){
        int n; cin>>n;
        cout<<numOperations(n)<<endl;
    }
    return 0;
}