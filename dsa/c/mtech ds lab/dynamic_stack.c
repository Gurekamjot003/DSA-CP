#include <stdio.h>
#include <stdlib.h>
const int INT_MIN = -(1 << 30);

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    int *arr, top, capacity;
} stack;

stack *init_stack()
{
    stack *ans = (stack *)malloc(sizeof(stack));
    if (!ans)
        return NULL;
    ans->capacity = 4;
    ans->arr = (int *)malloc(sizeof(int) * ans->capacity);
    if (!ans->arr)
    {
        free(ans);
        return NULL;
    }
    ans->top = -1;
    return ans;
}

int size(stack *st)
{
    return st->top + 1;
}

bool push(int val, stack *st)
{
    if (!st)
        return false;
    if (st->top + 1 == st->capacity)
    {
        st->capacity += st->capacity;
        int *new_arr = realloc(st->arr, sizeof(int) * st->capacity);
        if (!new_arr)
            return false;
        st->arr = new_arr;
    }
    st->arr[++st->top] = val;
    return true;
}

int top(stack *st)
{
    if (!st || st->top == -1)
        return INT_MIN;
    return st->arr[st->top];
}

bool pop(stack *st)
{
    if (!st || st->top == -1)
        return false;
    st->top--;
    if (st->capacity > 4 && st->top + 1 <= st->capacity / 4)
    {
        st->capacity /= 2;
        int *new_arr = (int *)realloc(st->arr, sizeof(int) * st->capacity);
        if (new_arr)
            st->arr = new_arr;
    }
    return true;
}

int main()
{

    return 0;
}