#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef enum
{
    RED,
    BLACK
} Color;
typedef struct Node
{
    int val;
    struct Node *left, *right, *parent;
    Color color;
} Node;

Node *nil;

Node *init_null()
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->color = BLACK;
    ans->left = ans->right = ans->parent = NULL;
    return ans;
}

Node *init_node(int val, Node *left, Node *right)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = left;
    ans->right = right;
    ans->parent = nil;
    ans->color = RED;
    return ans;
}

void right_rotate(Node *node)
{
    Node *child = node->left;
    Node *child_right_subtr = child->right;
    child->parent = node->parent;
    if (child->parent != nil)
    {
        if (child->val <= child->parent->val)
            child->parent->left = child;
        else
            child->parent->right = child;
    }
    child->right = node;
    node->parent = child;
    node->left = child_right_subtr;
    if (child_right_subtr != nil)
        child_right_subtr->parent = node;
}

void left_rotate(Node *node)
{
    Node *child = node->right;
    Node *child_left_subtr = child->left;
    child->parent = node->parent;
    if (child->parent != nil)
    {
        if (child->val <= child->parent->val)
            child->parent->left = child;
        else
            child->parent->right = child;
    }
    child->left = node;
    node->parent = child;
    node->right = child_left_subtr;
    if (child_left_subtr != nil)
        child_left_subtr->parent = node;
}

void swap_colors(Node *a, Node *b)
{
    Color temp = a->color;
    a->color = b->color;
    b->color = temp;
}

Node *get_uncle(Node *node)
{
    if (node == nil || node->parent == nil || node->parent->parent == nil)
        return NULL;
    if (node->parent == node->parent->parent->left)
        node->parent->parent->right; // if parent is left child
    else
        return node->parent->parent->left;
}

void insert(Node *root, Node *new_node)
{
    if (root == NULL)
    {
        return;
    } // root shouldn't be a null node => user should only insert through insert into tree function after creating a tree using init tree
    Node *ptr = root, *parent = nil;

    while (ptr != nil)
    {
        parent = ptr;
        if (new_node->val <= ptr->val)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }

    if (new_node->val <= parent->val)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;
}

void insert_fix(Node *node)
{ // this node is having red color
    if (node->color == BLACK || (node->parent != nil && node->parent->color == BLACK))
        return; // node is black or parent is black

    Node *parent = node->parent;
    while (parent != nil && parent->color == RED)
    {
        Node *grand_parent = parent->parent;
        Node *uncle = get_uncle(node);
        // case 1 uncle is red
        if (uncle->color == RED)
        {
            uncle->color = parent->color = BLACK;
            grand_parent->color = RED;
        }

        // case 2 uncle is black
        else
        {

            // case 2.1 node is right child of parent
            if (node == parent->right)
            {
                left_rotate(parent);
                node = parent;
                parent = node->parent;
            }
            // case 2.2 node is left child of parent
            if (node == parent->left)
            {
                swap_colors(parent, grand_parent);
                right_rotate(grand_parent);
            }
        }

        node = grand_parent;
        parent = node->parent;
    }

    if (parent == nil)
        node->color = BLACK;
}

Node *init_tree()
{
    return nil = init_null();
}

void insert_into_tree(Node *root, int val)
{
    Node *new_node = init_node(val, nil, nil);
    insert(root, new_node);
    insert_fix(new_node);
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    if(root->val == val) return root;
    if(root->val>val) return search(root->left, val);
    return search(root->right, val);
}

Node* inorder_predecessor(Node* cur){
    if(!cur) return NULL;
    if(cur->left){ // then it will be present on right spine of left subtree
        Node* ptr = cur->left;
        while(ptr->right) ptr = ptr->right;
        return ptr;
    }
    Node* ptr = cur;
    while(ptr->parent && ptr->parent->left == ptr){
        ptr = ptr->parent;
    }
    if(!ptr->parent) return NULL;
    return ptr->parent;
}

Node* inorder_successor(Node* cur){
    if(!cur) return NULL;
    if(cur->right){ // then it will be present on left spine of right subtree
        Node* ptr = cur->right;
        while(ptr->left) ptr = ptr->left;
        return ptr;
    }
    Node* ptr = cur;
    while(ptr->parent && ptr->parent->right == ptr){
        ptr = ptr->parent;
    }
    if(!ptr->parent) return NULL;
    return ptr->parent;
}

Node* get_sibling(Node* node){
    if(node->parent == nil) return NULL;
    if(node->parent->left == node) return node->parent->right;
    return node->parent->left;
}

Node* get_far_nephew(Node* node){
    if(node->parent == nil) return NULL;
    if(node->parent->left == node) return node->parent->right->right;
    return node->parent->left->left;
}

Node* get_near_nephew(Node* node){
    if(node->parent == nil) return NULL;
    if(node->parent->left == node) return node->parent->right->left;
    return node->parent->left->right;
}

void delete_fix(Node* node){
    // case 1 red node
    if(node->color == RED) return; // direclty deleted 
    
    // case 2 root is double black
    if(node->parent == nil) return; 
    
    Node* parent = node->parent;
    while(node->color == BLACK && node->parent != nil){
        // case 3 sibling black both sibling children black
        Node* sibling = get_sibling(node), *far_nephew = get_far_nephew(node), *near_nephew = get_near_nephew(node);
        if(sibling->color == BLACK && near_nephew == BLACK && far_nephew == BLACK){
            sibling->color = RED;
            if(parent->color == RED){
                parent->color = BLACK;
                return;
            }
            else node = parent;
        }

        // case 4 sibling color red
        else if(sibling->color == RED){ // parent will always be black
            swap_colors(sibling, parent);
            if(node == parent->left) left_rotate(parent);
            else right_rotate(parent);
        }
        
        // case 5 sibling black, far nephew black, near nephew red
        else if(sibling->color = BLACK && far_nephew->color == BLACK && near_nephew->color == BLACK){
            swap_colors(sibling, near_nephew);
            if(node == parent->left) right_rotate(sibling);
            else left_rotate(sibling);
        }

        // case 6 
        else if(sibling->color == BLACK && far_nephew->color == RED){
            swap_colors(parent, sibling);
            if(node == parent->left) left_rotate(parent);
            else right_rotate(parent);
            far_nephew->color = BLACK;
            return;
        }

        parent = node->parent;
    }

}

void delete(Node** root, int val){
    Node* ptr = *root;
    Node* parent = ptr->parent;
    while(ptr){
        if(ptr->val == val){
            if(ptr->left){
                Node* replacement = inorder_predecessor(ptr);
                ptr->val = replacement->val;
                ptr = replacement;
                val = replacement->val;
            }
            else if(ptr->right){
                Node* replacement = inorder_successor(ptr);
                ptr->val = replacement->val;
                ptr = replacement;
                val = replacement->val;
            }
            else{ // leaf node => only case in which actual node is deletd from tree
                delete_fix(ptr);
                if(parent == nil){ // this is the case where root is the only element in tree & that is to be deleted
                    free(ptr);
                    *root = nil;
                    return;
                }
                if(ptr == parent->left){
                    parent->left = nil;
                }
                else parent->right = nil;
                free(ptr);
                return;
            }

        }
        else if(ptr->val < val){
            ptr = ptr->left;
        }
        else ptr = ptr->right;
        parent = ptr->parent;
    }
}

Node* delete_from_tree(Node* root, int val){
    delete(&root, val);
}

int main()
{
    Node *root = init_tree();
    insert_into_tree(root, 5);
    int arr[] = {10, 23, 3, 42, 32};
    for (int i = 0; i < 5; i++)
        insert_into_tree(root, arr[i]);
    printf("inserted successfully");
}