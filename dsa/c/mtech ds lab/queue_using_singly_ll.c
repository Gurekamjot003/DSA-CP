#include<stdio.h>
#include<stdlib.h>

typedef enum{
    FALSE = 0, TRUE = 1
} boolean;

typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node* init_node(int val, Node* next){
    Node* ans = (Node*) malloc(sizeof(Node));
    ans->val = val;
    ans->next = next;
}

Node* search(Node* head, int val){
    while(head && head->val != val) head = head->next;
    return head;
}

Node* insert(Node* head, int val, int target){
    Node* prev = search(head, target);
    if(prev){
        Node* cur = init_node(val, prev->next);
        prev->next = cur;
    }
    return head;
}

Node* delete(Node* head, int target){
    Node* to_delete = search(head, target);
    // case 1 node not found
    if(!to_delete) return head;
    // case 2 node is head itself
    if(to_delete == head){
        Node* ans = head->next;
        free(head);
        return ans;
    }
    // case 3 node is anywhere but not head
    Node* ptr = head;
    while(ptr && ptr->next != to_delete) ptr = ptr->next;
    ptr->next = ptr->next->next;
    free(to_delete);
    return head;
}

Node* delete_all(Node* head){
    Node* ptr = head;
    while(ptr){
        Node* next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return NULL;
}

typedef struct
{
    int size;
    Node* front, *back;
} Queue;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

Queue *init()
{
    Queue *ans = (Queue *)malloc(sizeof(Queue));
    ans->size = 0;
    ans->front = ans->back = NULL;
    return ans;
}

boolean is_empty(Queue *q)
{
    if (q->size== 0)
        return TRUE;
    return FALSE;
}

boolean push(Queue *q, int val)
{
    if (is_empty(q))
    {
        q->front = q->back = init_node(val, NULL);
    }
    else{
        q->back->next = init_node(val, NULL);
        q->back = q->back->next;
    }
    q->size++;
    return TRUE;
}

int get_front(Queue *q)
{
    if (is_empty(q))
        return -1;
    return q->front->val;
}

boolean pop(Queue *q)
{
    if (is_empty(q))
        return FALSE;
    
    Node* to_delete = q->front;
    if (q->front == q->back)
    {
        q->front = NULL;
        q->back = NULL;
    }
    else{
        q->front = q->front->next;
    }
    free(to_delete);
    q->size--;
    return TRUE;
}

int main()
{
    Queue *q = init();

    push(q, 5);
    push(q, 6);
    printf("%d\n", get_front(q));
    pop(q);
    pop(q);
    if (get_front(q) == -1)
        printf("Q is empty\n");
    else
        printf("%d\n", get_front(q));

    push(q, 7);

    return 0;
}