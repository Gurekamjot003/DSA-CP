#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v = {1,2,3,4,5,6};
    // for(int i=0; i<v.size(); i++){
    //     cin>>v[i];
    // }
    int occurance=0;
    int x = 10;
    cout<<"Enter element: ";
    // cin>>x;
    for(int i=0; i<v.size(); i++){
        if(x<v[i]){
            occurance+=1;
        }
    }
    cout<<"No of occurances = "<<occurance;
    return 0;
}