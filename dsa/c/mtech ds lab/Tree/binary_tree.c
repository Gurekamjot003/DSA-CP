#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef enum boolean
{
    FALSE = 0,
    TRUE = 1
} boolean;



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

Node *get_left_node(Node *root)
{
    if (root)
        return root->left;
    return NULL;
}
Node *get_right_node(Node *root)
{
    if (root)
        return root->right;
    return NULL;
}

Node *search_key(Node *root, int val)
{
    while (root)
    {
        if (root->val == val)
            return root;
        root = val < root->val ? root->left : root->right;
    }
    return NULL;
}

Node *insert_left(Node *root, int parent, int val, boolean place_at_left)
{
    Node *target = search_key(root, parent);
    if (!target)
        return root;

    Node *og_node = target->left;
    if (place_at_left)
        target->left = init_node2(val, og_node, NULL);
    else
        target->left = init_node2(val, NULL, og_node);
    return target->left;
}

Node *delete_node(Node *root, int val)
{
    Node *target = search_key(root, val);
    if (!target)
        return root;

    if (!target->left)
    {
        Node *replacement = target->right;
        if (!target->parent)
            root = replacement;
        else if (target == target->parent->left)
            target->parent->left = replacement;
        else
            target->parent->right = replacement;
        if (replacement)
            replacement->parent = target->parent;
        free(target);
        return root;
    }

    if (!target->right)
    {
        Node *replacement = target->left;
        if (!target->parent)
            root = replacement;
        else if (target == target->parent->left)
            target->parent->left = replacement;
        else
            target->parent->right = replacement;
        if (replacement)
            replacement->parent = target->parent;
        free(target);
        return root;
    }

    Node *successor = target->right;
    while (successor->left)
        successor = successor->left;

    if (successor->parent != target)
    {
        Node *successor_child = successor->right;
        successor->parent->left = successor_child;
        if (successor_child)
            successor_child->parent = successor->parent;
        successor->right = target->right;
        successor->right->parent = successor;
    }

    if (!target->parent)
        root = successor;
    else if (target == target->parent->left)
        target->parent->left = successor;
    else
        target->parent->right = successor;
    successor->parent = target->parent;
    successor->left = target->left;
    successor->left->parent = successor;
    free(target);
    return root;
}

int main()
{
}