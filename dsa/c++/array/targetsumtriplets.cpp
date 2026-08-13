//count the no of triplets whose sum is equal to n
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int array[]={1,2,5,2,3,1,4,2};
    int ans=0;
    int size=8;
    int targetsum=5;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1;k<size;k++){
                if(array[i]+array[j]+array[k]==targetsum){
                    ans++;
                }
            }
        }
    }
    cout<<"no of triplets with targetsum as "<<targetsum<<" is "<<ans;
    return 0;
}