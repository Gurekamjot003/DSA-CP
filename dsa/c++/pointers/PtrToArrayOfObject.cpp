#include<iostream>
using namespace std;

class item{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id=a; price=b;
        }
        void getData(){
            cout<<"Your item code is: "<<id<<endl<<"Item's price is: "<<price<<endl;
        }
};

int main(){
    item *ptr = new item[3];
    item *ptrTemp=ptr;
    int a,i;
    float b;
    for(i=0; i<3; i++){
        cout<<"Enter the item id and item price for item no. "<<i+1<<endl;
        cin>>a>>b;
        (ptr++)->setData(a,b);
    }
    for(i =0; i<3; i++){
        (ptrTemp++)->getData();
    }
    return 0;
}