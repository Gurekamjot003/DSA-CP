#include<bits/stdc++.h>
using namespace std;
class Solution {

    void dfs(string endWord, string beginWord, map<string, vector<string>>& prev, vector<string>& cur, vector<vector<string>>& ans){
        if(endWord == beginWord){
            vector<string> rev = cur;
            reverse(rev.begin(), rev.end());
            ans.push_back(rev);
            return;
        }
        if(prev.find(endWord) == prev.end()) return;
        for(int i = 0; i<prev[endWord].size(); i++){
            cur.push_back(prev[endWord][i]);
            dfs(cur.back(), beginWord, prev, cur, ans);
            cur.pop_back();
        }
    }
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        map<string, vector<string>> prev;
        while(!q.empty()){
            int sz = q.size(); 
            set<string> to_erase;
            while(sz--){
                string cur_word = q.front();
                q.pop();
                for(int i = 0; i<cur_word.size(); i++){
                    for(int j = 0; j<26; j++){
                        string to_find = cur_word;
                        to_find[i] = 'a'+j;
                        if(st.find(to_find) != st.end()){
                            if(to_erase.find(to_find) == to_erase.end()) q.push(to_find);
                            prev[to_find].push_back(cur_word);
                            to_erase.insert(to_find);
                        }
                    }
                }
            }
            for(auto& s: to_erase) st.erase(s);
        }
        vector<vector<string>> ans;
        vector<string> cur = {endWord};
        dfs(endWord, beginWord, prev, cur, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> ans = sol.findLadders("red", "tax", wordList);
    for(auto& n: ans){
        for(auto& m: n) cout<<m<<" ";
        cout<<endl;
    }
}