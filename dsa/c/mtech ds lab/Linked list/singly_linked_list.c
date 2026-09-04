#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *init_node(int val, Node *next)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    if (!ans)
        return NULL;
    ans->val = val;
    ans->next = next;
    return ans;
}

Node *search(Node *head, int val)
{
    while (head && head->val != val)
        head = head->next;
    return head;
}

Node *insert(Node *head, int val, int target)
{
    Node *prev = search(head, target);
    if (prev)
    {
        Node *cur = init_node(val, prev->next);
        prev->next = cur;
    }
    return head;
}

Node *delete(Node *head, int target)
{
    Node *to_delete = search(head, target);
    // case 1 node not found
    if (!to_delete)
        return head;
    // case 2 node is head itself
    if (to_delete == head)
    {
        Node *ans = head->next;
        free(head);
        return ans;
    }
    // case 3 node is anywhere but not head
    Node *ptr = head;
    while (ptr && ptr->next != to_delete)
        ptr = ptr->next;
    if (ptr)
        ptr->next = ptr->next->next;
    free(to_delete);
    return head;
}

Node *delete_all(Node *head)
{
    Node *ptr = head;
    while (ptr)
    {
        Node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return NULL;
}

int main()
{
}