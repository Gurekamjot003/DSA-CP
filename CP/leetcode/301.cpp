#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool is_valid(string& s){
        int cur = 0;
        for(auto& ch: s){
            if(ch == '(') cur++;
            else if(ch == ')') cur--;
            if(cur<0) return false;
        }
        return cur == 0;
    }

    void btk(string& s, set<string>& ans, int& max_sz, string& cur, int i = 0){
        if(i == s.size()){

            if(!is_valid(cur)) return;
        
            if((int)cur.size() > max_sz){
                ans.clear();
                ans.insert(cur);
            
                max_sz = cur.size();
            }
            else if((int)cur.size() == max_sz){
                ans.insert(cur);
            }
            return;
        }
        if(s[i] == '(' or s[i] == ')'){
            btk(s, ans, max_sz, cur, i+1);
        }
        
        cur.push_back(s[i]);
        btk(s, ans, max_sz, cur, i+1);
        cur.pop_back();
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        int max_sz = INT_MIN;
        string cur;
        btk(s, ans, max_sz, cur);
    
        return vector<string>(ans.begin(), ans.end());
    }
};