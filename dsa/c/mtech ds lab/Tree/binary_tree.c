#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{
    FALSE = 0, TRUE = 1
} boolean;

typedef struct Node{
    int val;
    struct Node* left, *right, *parent;
}Node;

Node* init_node(int val){
    Node* ans = (Node*)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = NULL;
    return ans;
}

Node* init_node2(int val, Node* left_subtree, Node* right_subtree){
    Node* ans = (Node*)malloc(sizeof(Node));
    ans->val = val;
    ans->left = left_subtree;
    ans->right = right_subtree;
    ans->parent = NULL;
    if(ans->left) ans->left->parent = ans;
    if(ans->right) ans->right->parent = ans;
    return ans;
}

Node* get_left_node(Node* root){
    if(root) return root->left;
    return NULL;
}
Node* get_right_node(Node* root){
    if(root) return root->right;
    return NULL;
}

Node* search_key(Node* root, int val){
    if(root->val == val) return root;
    Node* left = search_key(root->left, val), *right = search_key(root->left, val);
    if(left) return left;
    return right;
}

Node* insert_left(Node* root, int parent, int val, boolean place_at_left){
    Node* target = search_key(root, parent);
    // case 1 parent not found
    if(!target) return root;

    Node* og_node = target->left;
    if(place_at_left) target->left = init_node2(val, og_node, NULL);
    else target->left = init_node2(val, NULL, og_node);
    return target->left;
}

Node* delete_node(Node* root, int val){

    Node* target = search_key(root, val);
    if(!target) return root;

    // only 1 child cases
    if(!target->left){
        
    }
    if(target != root){
        Node* parent = target->parent;
        if(parent->left == target)
    }
}


int main(){

}