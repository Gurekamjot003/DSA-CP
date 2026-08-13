//Find the second largest element in the given Array.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array[]={5,100,14,549,54,4,549};
    int largest=0;
    int seclar=0;
    int size=7;
    for(int i=0; i<size; i++){
        if(array[i]>largest){
            seclar=largest;
            largest=array[i];
        }
        else if(array[i]>seclar){
            seclar=array[i];
        }
    }
    cout<<seclar;
    return 0;
}