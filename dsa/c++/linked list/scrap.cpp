#include<iostream>
using namespace std;

int main(){
    cout<<'[';
    for(int i = 0; i<100; i++){
        cout<<"100";
        if(i!=99) cout<<", ";
    }
    cout<<']';
    return 0;
}