#include <stdio.h>
#include <stdlib.h>

typedef enum boolean
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct Node
{
    int val;
    struct Node *left, *right, *parent;
} Node;

Node *init_node(int val)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = NULL;
    return ans;
}

Node *init_node2(int val, Node *left_subtree, Node *right_subtree)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = left_subtree;
    ans->right = right_subtree;
    ans->parent = NULL;
    if (ans->left)
        ans->left->parent = ans;
    if (ans->right)
        ans->right->parent = ans;
    return ans;
}

void preorder(Node* root){
    if(!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorderd(Node* root){
    if(!root) return;
    preorder(root->left);
    printf("%d ", root->val);
    preorder(root->right);
}

void inorderd(Node* root){
    if(!root) return;
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->val);
}

int main(){
    return 0;
}