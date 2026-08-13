#include<iostream>
#include<list>
using namespace std;

void div(int n, list<int> &l){
    int temp=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            l.push_back(i);
            temp++;
        }
    }
}

void display(list<int> &l){
    for(auto it : l){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int a,b,gcd=1;
    list<int> l1,l2;
    cin>>a>>b;
    div(a, l1);
    div(b, l2);
    
    list<int> :: iterator it1= --l1.end();
    list<int> :: iterator it2 = --l2.end();
    while(it1 != l1.begin() && it2 != l2.begin()){
        if(*it2>*it1){
            it2--;
        }
        else if(*it2< *it1){
            it1--;
        }
        else{
            gcd=*it1;
            break;
        }
    }
    cout<<gcd;
    return 0;
}