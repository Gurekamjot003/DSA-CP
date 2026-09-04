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
    int size, height;
} Node;

Node *init_node(int val)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = NULL;
    ans->size = 1;
    ans->height = 0;
    return ans;
}

int get_height(Node *node)
{
    if (!node)
        return -1;
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    int ans = left_height;
    if (right_height > ans)
        ans = right_height;
    return ans + 1;
}

int get_size(Node *node)
{
    if (!node)
        return 0;
    int left_size = get_size(node->left);
    int right_size = get_size(node->right);
    int ans = left_size + right_size;
    return ans + 1;
}

void update(Node *node)
{
    if (!node)
        return;

    update(node->left);
    update(node->right);
    node->size = 1;
    if (node->left)
        node->size += node->left->size;
    if (node->right)
        node->size += node->right->size;
    node->height = -1;
    if (node->left && node->left->height > node->height)
        node->height = node->left->height;
    if (node->right && node->right->height > node->height)
        node->height = node->right->height;
    node->height++;
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
    update(ans);
    return ans;
}

void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorderd(Node *root)
{
    if (!root)
        return;
    inorderd(root->left);
    printf("%d ", root->val);
    inorderd(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
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
    update(root);
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
        update(root);
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
        update(root);
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
    update(root);
    return root;
}

int main()
{
    return 0;
}