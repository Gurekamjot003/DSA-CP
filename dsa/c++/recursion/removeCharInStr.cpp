#include<iostream>
#include<string>
using namespace std; 

string remove(char ch, int ind, string s){
    string ans;
    if(ind == s.size()) return ans;
    if(s[ind] != ch){
        ans.push_back(s[ind]);
    }
    
    ans+= remove(ch, ind+1, s);
    return ans;
    
}

int main(){
    string s = "abcax";
    cout<<remove('a', 0, s);
    return 0;
}