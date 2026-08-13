// wap to copy a string using operator < overloading

#include<iostream>
#include<string.h>
using namespace std;

class space{
    public:
    char s1[100];
    void setData(){
        cin>>s1;
    }
    void display(){
        cout<<s1<<endl;
    }
    void operator <(space &s){
        strcpy(s1,s.s1);
    }
        
};

int main(){
    space s;
    s.setData();
    s.display();
    space sc;
    sc<s;
    sc.display();
    return 0;
}