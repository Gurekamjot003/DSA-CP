#include<iostream>
#include<string>
using namespace std;

int reverse(int num){
    
    int lastdig = num%10;
    if((num/10) >0)
        return reverse(num/10) + lastdig*10;
    return lastdig;
}

bool palin(int num, int lptr, int rptr){
    string s = to_string(num);
    if(lptr>=rptr) return true;
    if(s[lptr] != s[rptr]) return false;
    return palin(num, lptr+1, rptr-1);
}

int main(){
    int num1 = 12321;
    int num2 = 12325;
    cout<<palin(num1, 0, 4)<<endl<<palin(num2, 0, 4);
    return 0;
}