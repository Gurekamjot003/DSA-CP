//sorting array containing 0s and 1s using 2 pointer solution
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int n,ele;
    cout<<"Enter no of elements you want to add in array: ";
    cin>>n;
    cout<<"Enter the elements(only 0s and 1s): ";
    for(int i=0;i<n; i++){
        cin>>ele;
        v.push_back(ele);
    }
    int left_ptr=0,right_ptr=v.size()-1;            //solution starts from here
    while(left_ptr<right_ptr){
        if(v[left_ptr]==1 && v[right_ptr]==0){
            v[left_ptr++]=0;
            v[right_ptr--]=1;
        }
        if(v[left_ptr]==0){
            left_ptr++;
        }
        if(v[right_ptr]==1){
            right_ptr--;
        }

    }
    for(int i=0; i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}