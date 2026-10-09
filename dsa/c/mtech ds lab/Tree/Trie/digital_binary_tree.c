#include<stdio.h>
#include<string.h>

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef struct Node
{
    char* key;
    struct Node *left, *right;
} Node;

Node *init_node(char* key)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->key = key;
    ans->left = ans->right = NULL;
    return ans;
}

bool insert(Node** root, char* key){
    Node* parent = NULL;
    Node* cur = *root;
    int i = 0;
    while(cur){
        parent = cur;
        if(i == strlen(key)){
            if(strcmp(key, cur->key) == 0) return false; // already present
            char* new_key = cur->key;
            cur->key = key;
            key = new_key;
        }
        if(key[i++] == '0') cur = cur->left;
        else cur = cur->right;
    }
    if(!parent) *root = init_node(key);
    else if(key[i-1] == '0') parent->left = init_node(key);
    else parent->right = init_node(key);
    return true;
}

bool search(Node* root, char* key){
    int i = 0;
    while(root && i<strlen(key)){
        if(strcmp(root->key, key) == 0) return true;
        if(key[i++] == '0') root = root->left;
        else root = root->right;
    }
    return false;
}

Node* inorder_predecessor(Node* cur){
    if(!cur) return NULL;
    if(cur->left){ // then it will be present on right spine of left subtree
        Node* ptr = cur->left;
        while(ptr->right) ptr = ptr->right;
        return ptr;
    }
    return NULL;
}

Node* inorder_successor(Node* cur){
    if(!cur) return NULL;
    if(cur->right){ // then it will be present on left spine of right subtree
        Node* ptr = cur->right;
        while(ptr->left) ptr = ptr->left;
        return ptr;
    }
    return NULL;
}

void free_node(Node* node){
    free(node->key);
    free(node);
}

void swap_keys(Node* n1, Node* n2){
    char* temp = n1->key;
    n1->key = n2->key;
    n2->key = temp;
}

bool delete(Node** root, char* key){
    Node* parent = NULL;
    Node* cur = *root;
    int i = 0;
    while(cur){
        if(strcmp(cur->key, key) == 0){
            Node* replacement;
            if(cur->left){
                replacement = inorder_predecessor(cur);
                swap_keys(replacement, cur);
                parent = cur;
                cur = cur->left;
            }
            else if(cur->right){
                replacement = inorder_successor(cur);
                swap_keys(replacement, cur);
                parent = cur;
                cur = cur->right;
            }
            else{
                if(parent){
                    if(cur == parent->left) parent->left = NULL;
                    else parent->right = NULL;
                }
                else *root = NULL;
                free(cur);
                return true;
            }
            continue;
        }
        parent = cur;
        if(i == strlen(key)){
            if(strcmp(key, cur->key) == 0) return false; // already present
            char* new_key = cur->key;
            cur->key = key;
            key = new_key;
        }
        if(key[i++] == '0') cur = cur->left;
        else cur = cur->right;
    }
    if(!parent) *root = init_node(key);
    else if(key[i-1] == '0') parent->left = init_node(key);
    else parent->right = init_node(key);
    return true;
}