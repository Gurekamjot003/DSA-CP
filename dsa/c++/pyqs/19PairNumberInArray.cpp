//wap to read a list of 10 integer numbers and print all those numbers which have a pair of 2 digits(combined) number in it.

#include<iostream>
using namespace std;

class Array{
    int arr[10]={256,264,65,4,354,646,465,4654,654,5422};
    int val;
    public:
    void displayArr(){
        cout<<"Array is as follows: "<<endl;
        for(int i=0; i<10; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void setVal(){
        cout<<"Enter 2 digit number pair "<<endl;
        cin>>val;
    }
    void getData(){
        for(int i=0; i<10; i++){
            bool flag=0;
            int temp=arr[i];
            while(temp>0){
                int digitPair=temp%100;
                if(digitPair==val){
                    flag=1;
                }
                temp/=10;
            }
            if(flag==1){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
};

int main(){
    Array a;
    a.displayArr();
    a.setVal();
    a.getData();
    
    return 0;
}