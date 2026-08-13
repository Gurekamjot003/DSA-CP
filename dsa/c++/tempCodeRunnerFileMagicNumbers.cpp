#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    //int array[3][3]={1,2,3,4,5,6,7,8,9};
    int array[]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9; i++){
        for(int j=i+1; j<9;j++){
            for(int k=j+1; k<9; k++){
                if(array[i] + array[j] + array[k]==15){
                    v.push_back(array[i]);
                    v.push_back(array[j]);
                    v.push_back(array[k]);
                    
                }
                
            }            
        }
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    return 0;
}