#include <stdio.h>
#include <stdlib.h>
typedef enum boolean
{
    false = 0,
    true = 1
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

typedef struct
{
    Node *arr[100];
    int top;
} stack;

stack init_stack()
{
    stack ans;
    ans.top = -1;
    return ans;
}

int size(stack *st)
{
    return st->top + 1;
}

boolean push(stack *st, Node *node)
{
    if (st->top == 99)
        return false;
    st->arr[++st->top] = node;
    return true;
}

Node *peek(stack *st)
{
    if (st->top == -1)
        return NULL;
    return st->arr[st->top];
}

boolean pop(stack *st, Node **node)
{
    if (st->top == -1)
        return false;
    *node = st->arr[st->top--];
    return true;
}

void preorder(Node *root)
{
    if (!root)
        return;
    stack st = init_stack();
    push(&st, root);
    while (size(&st))
    {
        Node *node;
        pop(&st, &node);
        printf("%d ", node->val);
        if (node->right)
            push(&st, node->right);
        if (node->left)
            push(&st, node->left);
    }
}

void inorder(Node *root)
{
    stack st = init_stack();
    Node *node = root;
    while (node || size(&st))
    {
        while (node)
        {
            push(&st, node);
            node = node->left;
        }
        pop(&st, &node);
        printf("%d ", node->val);
        node = node->right;
    }
}

void postorder(Node *root)
{
    if (!root)
        return;
    stack st = init_stack();
    stack output = init_stack();
    push(&st, root);
    while (size(&st))
    {
        Node *node;
        pop(&st, &node);
        push(&output, node);
        if (node->left)
            push(&st, node->left);
        if (node->right)
            push(&st, node->right);
    }
    while (size(&output))
    {
        Node *node;
        pop(&output, &node);
        printf("%d ", node->val);
    }
}

int main()
{
    return 0;
}