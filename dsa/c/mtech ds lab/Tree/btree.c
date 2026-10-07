#include<stdio.h>
#include<stdlib.h>

const int t = 2; // for 2 3 4 tree

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;
typedef struct Node
{
    int keys[2*t - 1];
    struct Node* children[2*t];
    boolean leaf;
    int size;
} Node;

Node *init_root(int val) // init root
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->keys[0] = val;
    for(int i = 0; i<2*t; i++) ans->children[i] = NULL;
    ans->leaf = TRUE;
    ans->size = 1;
    return ans;
}

Node* init_node(int val, Node* left, Node* right){
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->keys[0] = val;
    ans->children[0] = left; ans->children[1] = right;
    if(left || right) ans->leaf = FALSE;
    else ans->leaf = TRUE;
    ans->size = 1;
    for(int i = 2; i<2*t; i++){
        ans->children[i] = NULL;
    } 
    return ans;
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    for(int i = 0; i<root->size; i++){
        if(root->keys[i] == val) return root;
        if(root->keys[i] > val){
            return search(root->children[i], val);
        }
    }
    return search(root->children[2*t-1], val);
}

Node* insert(Node* root, int val){
    if(!root){
        return init_root(val);
    }

    if(root->size == 2*t-1){
        
    }
}