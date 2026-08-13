#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> v(6);
    for(int i=0; i<v.size(); i++){
        cin>>v[i];
    }
    int occurance=0;
    int x=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>occurance){
            occurance=v[i];
        }
        else{
            x=1;
            break;
        }
    }
    if(x==0){
        cout<<"Sorted";
    }
    else{
        cout<<" Not sorted";
    }
    return 0;
}