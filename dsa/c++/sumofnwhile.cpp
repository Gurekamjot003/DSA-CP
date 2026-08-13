#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    int i=1;
    int sum=0;
    while (i<(n+1))
    {
        sum=sum+i;
        i++;
    }
    cout<<sum;
    return 0;
}