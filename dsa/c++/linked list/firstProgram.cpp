#include<iostream>
using namespace std;
class node{
    public:
        int val;            
        node * next;        //stores the location of next node
        node(int data){
            val=data;
            next = NULL;
        }
}; 

int main(){
    node *n= new node(1);
    cout<<n->val<<" "<<n->next;
    return 0;
}