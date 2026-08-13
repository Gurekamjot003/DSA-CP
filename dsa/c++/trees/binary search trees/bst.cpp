#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root){
    if(root == NULL) return;
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
}

