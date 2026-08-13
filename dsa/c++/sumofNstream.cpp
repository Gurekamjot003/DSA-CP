//do while
#include<iostream>
using namespace std;

int main(){
    int N;
    int sum=0;
    cout<<"Enter no. of integers to be summed in stream"<<endl;
    cin>>N;
    do
    {
        int n;
        cout<<"Enter no."<<endl;
        cin>>n;
        sum+=n;
        N--;
    } while (N>0);
    cout<<sum;
    
    return 0;
}