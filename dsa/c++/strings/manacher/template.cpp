#include<bits/stdc++.h>
using namespace std;

class Manacher{
    vector<int> dp;
    string s;

    void build(){
        int l = -1, r =1;
        int n = s.size();
        for(int i = 1; i<n; i++){

            //init using mirror
            int mirror = l +r -i;
            if(i<r && mirror >=0 && mirror <n) dp[i] = max(0, min(r - i, dp[mirror]));

            //inc until match found
            while((i-dp[i])>=0 && (i+dp[i])<s.size() && s[i+dp[i]] == s[i-dp[i]]) dp[i]++;
            
            //slide window if palindrome is long enough
            if((i+dp[i])>r){
                r = i+dp[i];
                l = i-dp[i];
            }
        }
    }

public:
    Manacher(string s){
       
        string temp;
        for(auto& ch: s){
            temp.push_back('#');
            temp.push_back(ch);
        }
        temp.push_back('#');
        this->s = temp;
        dp.resize(temp.size(),0);
        build();
    }

    int longest_palindrome_length(){
        int ans = 1;
        for(int i = 1; i<s.size(); i++){
            ans = max(ans, dp[i]);
        }
        return ans -1;
    }

    int longest_palindrome_index(){
        int max_len = longest_palindrome_length();
        for(int i = 0; i<s.size(); i++){
            if(dp[i] > max_len) return i;
        }
        return -1;
    }

    string longest_palindrome(){
        string ans;
        int index = longest_palindrome_index();
        int left = index - dp[index] + 1;
        int right = index + dp[index] - 1;
        for(; left<=right; left++) if(s[left] != '#') ans.push_back(s[left]);
        return ans;
    }
};

int main(){
    Manacher m("cbbd");
    cout<<m.longest_palindrome_length()<<endl;

}