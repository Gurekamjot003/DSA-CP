#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include "../queue.h"


Node *init_node(int val)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = NULL;
    return ans;
}

Node* insert(Node* root, int val){
    if(!root) return init_node(val);
    if(root->val>val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* remove(Node* root, int val){
    if(!root) return NULL;
    if(root->val == val){
        Node* ans = NULL;
        if(!root->left){
            ans = root->right;
            free(root);
        }
        else if(!root->right){
            ans = root->left;
            free(root);
        }
        else{
            Node* ptr = root->left;
            while(ptr->right){
                ptr = ptr->right;
            }
            root->val = ptr->val;
            root->left = remove(root->left, ptr->val);
            ans = root;
        }
        return ans;
    }
    else if(root->val < val) root->right = remove(root->right, val);
    else root->left = remove(root->left, val);
}

void print(Node* root){
    if(!root) printf(" NULLL ");
    Queue* q = init(100);
    
}

int main(){
    int arr[] = {6,5 ,34, 1,2, 3};
    Node* root = NULL;
    for(int i = 0; i<6; i++){
        insert(root, arr[i]);
    }

    return 0;
}