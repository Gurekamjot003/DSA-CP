#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct
{
    int *arr;
    int capacity;
    int front, back;
} Queue;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

Queue *init(int capacity)
{
    Queue *ans = (Queue *)malloc(sizeof(Queue));
    capacity = max(4, capacity);
    ans->arr = (int *)malloc(sizeof(int) * capacity);
    ans->front = -1, ans->back = -1;
    ans->capacity = capacity;
    return ans;
}

boolean is_empty(Queue *q)
{
    if (q->front == -1 && q->back == -1)
        return TRUE;
    return FALSE;
}

boolean is_full(Queue *q)
{
    if (q->front == (q->back + 1) % q->capacity)
        return TRUE;
    return FALSE;
}

boolean push(Queue *q, int val)
{
    if (is_full(q))
        return FALSE;
    if (is_empty(q))
    {
        q->front = 0;
    }
    q->back = (q->back + 1) % q->capacity;
    q->arr[q->back] = val;
    return TRUE;
}

int get_front(Queue *q)
{
    if (is_empty(q))
        return -1;
    return q->arr[q->front];
}

boolean pop(Queue *q)
{
    if (is_empty(q))
        return FALSE;
    q->front++;
    if (q->front == (q->back + 1) % q->capacity)
    {
        q->front = -1;
        q->back = -1;
    }
    return TRUE;
}

int main()
{
    Queue *q = init(5);

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