//wap to reverse an array and add the original values of the array to the corresponding values of the reversed array

#include<iostream>
using namespace std;

class Revarraysum{
    int arr[10];
    int revArr[10];
    int revSumArr[10];
    public:
        void setData(){
            for(int i=0; i<10; i++){
                cin>>arr[i];
            }
        }
        void getRevArray(){
            for(int i=0; i<10; i++){
                revArr[9-i]=arr[i];
            }
        }
        void getRevSumArr(){
            for(int i=0; i<10; i++){
                revSumArr[i]=arr[i]+revArr[i];
                cout<<revSumArr[i]<<endl;
            }
        }
};

int main(){
    Revarraysum r1;
    r1.setData();
    r1.getRevArray();
    r1.getRevSumArr();
    return 0;
}