//no of pairs in array which give a target sum
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int ans=0;
    int array[]={3,4,6,7,1};
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(array[i]+array[j]==7){
                ans++;
            }
        }
    }
    cout<<"no of pairs with target sum 7: "<<ans;
    return 0;
}