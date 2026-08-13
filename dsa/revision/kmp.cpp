// longest prefix suffix array
#include<bits/stdc++.h>
using namespace std;

class LPS{
    vector<int> lps;
    
public:
    LPS(string& s){
        int n = s.size();
        lps.resize(n);
        int pre = 0, suf = 1;
        while(suf<n){
            if(s[pre] == s[suf]) lps[suf++] = ++pre;
            else if(pre == 0) suf++;
            else pre = lps[pre-1];
        }
    }
};


// for any string matching question simply use a separator (like "$") in between 2 strings to be compared
// if pre_ptr becomes equal to the size of string to find return ans
int find_first_occurrence(string haystack, string needle){
    string combined_str = needle + "$" + haystack; //to find + separator("$") + search from
    int n = combined_str.size(), m = needle.size();
    vector<int> lps(n);
    int pre = 0, suf = 1;

    while(suf<n){
        if(combined_str[pre] == combined_str[suf]) lps[suf++] = ++pre;
        else if(pre == 0) suf++;
        else pre = lps[pre-1];

        if(pre == m) return suf-2*m-1; // word found, return start index of word
    }

    return -1;
}

int main(){
    cout<<find_first_occurrence("sadboysad", "sad")<<endl;
    cout<<find_first_occurrence("leetcode", "leeto")<<endl;
}