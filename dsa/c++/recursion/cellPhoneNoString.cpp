// Given a string containing digits from 2-9 inclusive, return all possible letter
// combinations that the number could represent. Return the answer in any order.
// Input: digits = "23"
// Output:
// ["ad", "ae", "af", "bd","be","bf", "cd","ce","cf"]

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void letterCombination(string digits, vector<string> keys, int i, string cur){
    if(i == digits.size()){
        cout<<cur<<" ";
        return;
    }
    for(int j = 0; j<keys[digits[i] - '0'].size(); j++){
        letterCombination(digits, keys, i+1, cur + keys[digits[i]-'0'][j]);
    }
}

int main(){
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digits = "79";
    // vector<string> result;
    string cur;
    letterCombination(digits, keys, 0, cur);
    return 0;
}
