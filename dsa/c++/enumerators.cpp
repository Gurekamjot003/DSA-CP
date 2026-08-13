#include<iostream>
using namespace std;

enum days_of_week{monday, tuesday,
wednesday, thursday, friday, saturday,
sunday};

int main(){
    days_of_week day1, day2;
    day1 = monday;
    day2 = tuesday;
    cout<<day2-day1;
    return 0;
}
    
    
    // cout<<fixed<<setprecision(8)<<double(22)/double(7);
    //cout<<setw(12)<<"My roll no is"<<setw(8)<<9101;
    // float a= 129.455396;
    // cout<<fixed<<setprecision(2)<<a<<endl;
    // cout<<fixed<<setprecision(3)<<a<<endl;