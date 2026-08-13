//Find the unique number in a given Array where all the elements are being repeated twice with one value being unique.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array[]={1,2,1,3,4,2,3};
    int size =7;
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            if(array[i]==array[j]){
                array[i]=-1;
                array[j]=-1;
            }
        }
    }
    for(int i=0; i<size; i++){
        if(array[i]!=-1){
            cout<<array[i];
        }
    }
    return 0;
}