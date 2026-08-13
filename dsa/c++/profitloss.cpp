#include<iostream>
using namespace std;

int main(){
    int cp,sp;
    cout<<"Enter cost price ";
    cin>>cp;
    cout<<"Enter selling price ";
    cin>>sp;
    if (sp>cp){
        cout<<"Its profit of "<<sp-cp;
    }
    else if(cp>sp){
        cout<<"Its loss of "<<cp-sp;
    }
    else{
        cout<<"No profit no loss";
    }
    return 0;
}