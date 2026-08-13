// wap to declare an array at run time and traversing it using pointers

#include<iostream>
using namespace std;

class A{
    int *ptr = new int[5];
    public:
    void setData(){
        for(int i=0; i<5; i++){
            cin>>*(ptr+i);
        }
    }
    void display(){
        for(int i=0; i<5; i++){
            cout<<*(ptr+i)<<endl;
        }
    }

};

int main(){
    A a;
    a.setData();
    a.display();
    return 0;
}