#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a binary no.: ";
    cin>>n;
    int temp=n;
    int sum=0;
    int temp2=1;
    while(temp>0){
        for(int i=0; i<n; i++){
            int lastdig=temp%10;
            sum+=lastdig*temp2;
            temp2*=2;
            temp=temp/10;
        }
    }
    cout<<sum;
    return 0;
}