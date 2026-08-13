//diff bw sum of even and odd indices
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array[]={1,2,1,2,1,2};
    int evensum=0;
    int oddsum=0;
    for(int i=0; i<6;i++){
        if(i%2==0){
            evensum+=array[i];
        }
        else{
            oddsum+=array[i];
        }
        
    }
    int diff;
    if(evensum>oddsum){
        diff=evensum-oddsum;
    }
    else{
       diff=oddsum-evensum;
    }
        cout<<"Difference = "<<diff;
    return 0;
}