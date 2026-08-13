// wap to concatenate 2 strings using + operator overloading

#include<iostream>
#include<string.h>
using namespace std;

class space{
    public:
    char s1[100];
        void setData(){
            cin.get(s1,100);
        }
        void display(){
            cout<<s1<<endl;
        }
        void operator +(space &s){
            cout<<strcat(s1, s.s1);
        }
};

int main(){

    space s;
    s.setData();
    s.display();
    space s2;
    s2.setData();
    s2.display();
    s+s2;
    
    return 0;
}