#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<int, int> mp, mp_freq;
    int get_max_val_from_mp(map<int, int>& mpfreq){
        auto it = mpfreq.rbegin();
        return (*it).first;
    }
    auto get_it(map<int, int>& mp, int i){
        auto it = mp.upper_bound(i);
        it--;
        return it;
    }
    void add_value(int i, int sz){
        mp[i] = sz;
        mp_freq[sz]++;
    }
    void remove_value(int i){
        int sz = mp[i];
        mp_freq[sz]--;
        if(mp_freq[sz] == 0) mp_freq.erase(sz);
        mp.erase(i);
    }
    void update_value(int i, int new_sz){
        remove_value(i);
        add_value(i, new_sz);
    }
    
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        mp.clear(); mp_freq.clear();
        s.push_back('0');
        int n = s.size();
        int count = 1;
        for(int i = 1; i<n; i++){
            if(s[i] != s[i-1]){
                int idx = i - count;
                add_value(idx, count);
                count = 1;
            }
            else count++;

        }
        s.pop_back();
        n--;
        vector<int> ans(queryIndices.size());
        for(int q = 0; q<queryCharacters.size(); q++){
           
            int i = queryIndices[q];
            // first remove ith char
            
            if(i<n-1 && s[i] == s[i+1]){
                auto it_cur = get_it(mp, i);
                int sz = (*it_cur).second - (i-(*it_cur).first + 1);
                add_value(i+1, sz);
            }
            if(i>0 && s[i] == s[i-1]){
                auto it_prev = get_it(mp, i-1);
                int idx = (*it_prev).first;
                int new_sz = i-(*it_prev).first;
                update_value(idx, new_sz);
            }
            if(mp.count(i)){
                remove_value(i);
            }

            // now we have to add new char
            
            
            s[i] = queryCharacters[q];
            if(i>0 && s[i] == s[i-1]){
                auto it_prev = get_it(mp, i-1);
                int new_sz = (*it_prev).second+1;
                int idx = (*it_prev).first;
                update_value(idx, new_sz);
            }
            else{
                add_value(i, 1);
            }
            if(i<n-1 && s[i] == s[i+1]){
                auto it_cur = get_it(mp, i),
                     it_next = get_it(mp, i+1);
                int new_sz = (*it_cur).second + (*it_next).second;
                int idx = (*it_cur).first;
                update_value(idx, new_sz);
                remove_value(i+1);
            }
            ans[q] = get_max_val_from_mp(mp_freq);

        }
        return ans;
    }
};
