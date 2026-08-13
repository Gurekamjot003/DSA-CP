#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char s[100]="My name  is Khan", ans[100];
    int j=0;
    for(int i=0; i<15; i++){
        if(s[i]=='\0'){
            break;
        }
        if(s[i]==' '){
            continue;
        }
        else{
            ans[j]=s[i];
            j++;
        }
    }
    ans[j]='\0';
    cout<<ans;
    return 0;
}