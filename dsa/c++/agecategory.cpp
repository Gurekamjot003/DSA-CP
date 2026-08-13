#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<"enter your age"<<endl;
    cin>>age;
    if(age<12){
        cout<<"child";
    }
    else if(age>=12&&age<18){
        cout<<"teenager";
    }
    else{
        cout<<"adult";
    }
    return 0;
}