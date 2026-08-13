// Function templates and function overloading

#include<iostream>
using namespace std;

class add{
    public:
        int sum(int a,int b){
            return a+b;
        }
        int sum(int a, int b, int c){
            return a+b+c;
        }
        template <typename type>
        type plus(type a, type b){
            return a+b;
        }
};

int main(){
    add a;
    cout<<a.sum(1,2)<<endl;
    cout<<a.sum(1,2,3)<<endl;
    cout<<a.plus(1.2, 2.5)<<endl;
    return 0;
}