#include "bst.cpp"
Node* insert(Node* root, int val){
    if(root == NULL) return new Node(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}