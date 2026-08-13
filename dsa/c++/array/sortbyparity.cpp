//move all the even integers to the beginning of the array followed by all the odd integers
#include<iostream>
#include<vector>
using namespace std;

int main(){
    //taking input
    vector<int> v;
    int n,ele;
    cout<<"Enter no of elements you want to add in array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n; i++){
        cin>>ele;
        v.push_back(ele);
    }
    int left_ptr=0,right_ptr=v.size()-1;            //solution starts from here
    while(left_ptr<right_ptr){
        if(v[left_ptr]%2!=0 && v[right_ptr]%2==0){
            int temp=v[left_ptr];
            v[left_ptr++]=v[right_ptr];
            v[right_ptr--]=temp;
        }
        if(v[left_ptr]%2==0){
            left_ptr++;
        }
        if(v[right_ptr]%2!=0){
            right_ptr--;
        }

    }
    //giving output
    for(int i=0; i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}