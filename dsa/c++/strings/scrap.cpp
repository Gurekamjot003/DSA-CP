#include<iostream>
#include<string>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
    for(int i=0; a[i]!='\0' && b[i]!='\0'; i++){
        if(a[i]==b[i]){
            cout<<"The value "<<a[i]<<" is same as "<< b[i]<<" at "<<i<<endl;
        }
    }
    return 0;
}