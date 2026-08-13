#include<iostream>
using namespace std;

class shop{
    int itemId[100];
    int itemPrice[100];
    int counter;
    public: 
        void initcounter(){ counter = 0;  }
        void getPrice();
        void displayPrice();
};

void shop :: getPrice(){
    cout<<"Enter the item id of item no. "<< counter + 1<<": ";
    cin>>itemId[counter];
    cout<<"Enter the price of the item: ";
    cin>>itemPrice[counter];
    counter++;
}

void shop :: displayPrice(){
    for(int i = 0; i< counter; i++){
        cout<<"The price of item id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
}

int main(){
    shop dukaan;
    dukaan.initcounter();
    dukaan.getPrice();
    dukaan.getPrice();
    dukaan.getPrice();
    dukaan.displayPrice();
    return 0;
}