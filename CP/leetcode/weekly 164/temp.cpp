#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = cards.size();
        int ans = 0;
        int cnt = 0;
        vector<int> st1(10, 0);
        vector<int> st2(10, 0);
        for(int i=0; i<n; i++){
            string str = cards[i];
            if(str[0] == x && str[1] == x){
                cnt++;
            } else if(str[0] == x){
                int pos = str[1]-'a';
                st1[pos]++;
            } else if(str[1] == x){
                int pos = str[0]-'a';
                st2[pos]++;
            }
        }
        int cnt1 = 0;
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                while(st1[j] && st1[i]){
                    cnt1++;
                    st1[j]--;
                    st1[i]--;
                }
                if(!st1[i]){
                    break;
                }
            }
        }
        ans += cnt1;
        int cnt2 = 0;
        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                while(st2[j] && st2[i]){
                    cnt2++;
                    st2[j]--;
                    st2[i]--;
                }
                if(!st2[i]){
                    break;
                }
            }
        }
        ans += cnt2;
        int unpaired = 0;
        for(int i=0; i<10; i++){
            while(st1[i] > 0){
                st1[i]--;
                unpaired++;
            }
        }
        for(int i=0; i<10; i++){
            while(st2[i] > 0){
                st2[i]--;
                unpaired++;
            }
        }
        ans += min(unpaired, cnt);
        if(cnt > unpaired) cnt -= unpaired;
        else cnt = 0;
        ans += std::min(cnt/2, cnt1+cnt2);
        return ans;
    }
};