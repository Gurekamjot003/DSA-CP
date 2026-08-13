#include<iostream>
#include<queue>
#include "binaryTrees.cpp"
using namespace std;



int main(){
    
    cout<<"Enter root value: ";
    int val;
    cin>> val;
    queue<Node*> q;
    Node* root;
    if(val!= -1){
        Node* n = new Node(val);
        q.push(n);
        root = n;
    }
    while(!q.empty()){
        Node * cur = q.front();
        q.pop();
        cout<<"Enter left child of "<<cur->val<<": ";
        cin>>val;
        if(val!= -1){
            cur->left = new Node(val);
            q.push(cur->left);
        }
        cout<<"Enter right child of "<<cur->val<<": ";
        cin>>val;
        if(val!= -1){
            cur->right = new Node(val);
            q.push(cur->right);
        }
    }
    
    cout << Node::leetcodeDisplay(root) << endl;  
    return 0;
}