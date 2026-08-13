#include "bst.cpp"

bool search(Node* root, int target){
    if(!root) return 0;
    if(root->val == target) return 1;
    return search(root->left, target) or search(root->right, target);
}