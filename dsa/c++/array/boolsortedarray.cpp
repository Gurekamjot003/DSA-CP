#include<iostream>
using namespace std;

int main(){
    bool sortedflag=true;
    int array[]={1,2,3,4,5,6};
    for(int i=1; i<6;i++){
        if(array[i]<array[i-1]){
            sortedflag=false;
            break;
        }
    }
    cout<<sortedflag;
    return 0;
}