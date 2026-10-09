#include<stdio.h>
#include<string.h>

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef struct Node
{
    bool valid;
    struct Node *left, *right;
} Node;

Node *init_node()
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->valid = false;
    ans->left = ans->right = NULL;
    return ans;
}

bool insert(Node** root, char* key){
    Node*cur = *root;
    for(int i = 0; i<strlen(key); i++){
        if(key[i] == '0'){
            if(!cur->left) cur->left = init_node();
            cur = cur->left;
        }
        else{
            if(!cur->right) cur->right = init_ndoe();
            cur = cur->right;
        }
    }
    if(cur->valid == true) return false; // already in trie
    cur->valid = true;
    return true;
}

bool search(Node* root, char* key){
    for(int i = 0; i<strlen(key); i++){
        if(key[i] == '0') root = root->left;
        else root = root->right;
        if(!root) return false;
    }
    return root->valid;
}

Node* delete_invalid(Node* root, char* key, int i){
    if(i<strlen(key)){
        if(key[i] == '0'){
            root->left = delete_invalid(root->left, key, i+1);
        }
        else{
            root->right = delete_invalid(root->right, key, i+1);
        }
    }
    if(root->left || root->right || root->valid == true){ // this is the case in which nodes should always exist
        return root;
    }
    free(root);
    return NULL;
}

bool delete(Node** root, char* key){
    Node*cur = *root;
    for(int i = 0; i<strlen(key); i++){
        if(key[i] == '0'){
            if(!cur->left) return false;
            cur = cur->left;
        }
        else{
            if(!cur->right) return false;
            cur = cur->right;
        }
    }
    
    if(cur->valid == false) return false;
    
    cur->valid = false;
    // now we need to delete nodes from the last required parent. This parent can be an LCA to a valid or valid itself
    *root = delete_invalid(*root, key, 0);
    return true;
}