#include<iostream>
using namespace std;

class binary{
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    int lptr=0;
    int rptr=9;
    int mid=(lptr+rptr)/2;
    int pos=-1;
    public:
    void display(){
        cout<<"Array: "<<endl;
        for(int i=0;i<10;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void search(int n){
        while(lptr<=rptr ){
            if(n<arr[mid]){
                rptr=mid-1;
            }
            else if(n>arr[mid]){
                lptr=mid+1;
            }
            if(arr[mid]==n){
                pos=mid;
                break;
            }
            mid=(lptr+rptr)/2;
        }
        if(pos==-1){
            cout<<"Element not present in list"<<endl;
        }
        else{
            cout<<"Element present at index: "<<pos<<endl;
        }
    }
};

int main(){
    binary b;
    b.display();
    b.search(20);
    return 0;
}