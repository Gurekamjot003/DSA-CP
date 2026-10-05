#include<stdio.h>
#include<stdlib.h>

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
typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct QNode
{
    Node *node;
    struct QNode* next;
} QNode;
typedef struct Queue{
    QNode* front, *back;
    int size;
} Queue;

QNode* init_QNode(Node* node){
    QNode* qnode = (QNode*)malloc(sizeof(QNode));
    qnode->node = node;
    qnode->next = NULL;
}

Queue* init_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->back = NULL;
    q->size = 0;
    return q;
}

boolean is_empty(Queue *q)
{
    if (q->size == 0)
        return TRUE;
    return FALSE;
}

void enqueue(Queue *q, Node* node)
{
    QNode* qnode = init_QNode(node);
    if (is_empty(q))
    {  
        q->front = qnode;
        q->back = qnode; 
    }
    else{
        q->back->next = qnode;
        q->back = qnode;
    }
    q->size++;
}

Node* get_front(Queue *q)
{
    return q->front->node;
}

void dequeue(Queue *q)
{
    if (!q || is_empty(q))
        return;
    QNode* qnode = q->front;
    q->front = q->front->next;
    if(!q->front) q->back = NULL;
    free(qnode);
    q->size--;
}

void free_tree(Node* root){
    if(!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print(Node* root){
    Queue* q = init_queue();

    enqueue(q, root);
    while(!is_empty(q)){
        int sz = q->size;
        while(sz--){

            Node* u = get_front(q);
            dequeue(q);
            if(!u) printf(" NULL ");
            else{
                printf(" %d ", u->val);
                enqueue(q, u->left);
                enqueue(q, u->right);
            }
        }
        printf("\n");
    }

}