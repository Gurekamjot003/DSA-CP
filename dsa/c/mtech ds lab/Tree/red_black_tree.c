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

Node *insert(Node *root, Node *new_node)
{
    if (root == NULL)
    {
        return NULL;
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

Node *insert_into_tree(Node *root, int val)
{
    Node *new_node = init_node(val, nil, nil);
    insert(root, new_node);
    insert_fix(new_node);
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