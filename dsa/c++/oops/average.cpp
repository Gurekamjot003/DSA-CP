#include<iostream>
using namespace std;
class average{
private:
    int n,x[50];
public:
    void getdata(){
        cout<<"Enter no of elements: ";
        cin>>n;
        cout<<"Enter the elements";        
        for(int i=0; i<n;i++){
            cin>>x[i];
        }
        
    }
    
    float avg(){
        int sum=0;
        float ans;
        for(int i=0;i<n;i++){
            sum+=x[i];
        }
        ans=sum/(n+0.0);
        return ans;
    }
};
int main(){
    average a;
    int n;
    
    a.getdata();
    cout<<a.avg();
    return 0;
}