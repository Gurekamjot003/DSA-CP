#include<stdio.h>
#include<stdlib.h>




typedef enum{
false, true
} bool;

typedef struct{
    int*arr, top, capacity;
} stack;

stack* init_stack(){
    stack* ans = (stack*)malloc(sizeof(stack));
    ans->capacity = 4;
    ans->arr = (int*)malloc(ans->capacity);
    ans->top = -1;
}

int size(stack* st){
    return st->top+1;
}

bool push(int val, stack* st){
    st->top++;
    if(st->top == st->capacity){
        st->capacity += st->capacity;
        st->arr = realloc(st->arr, st->capacity);
        if(!st->arr) return false;
    }
    st->arr[st->top] = val;
    return true;
}

int top(stack* st){
    if(st->top == -1) return INT_MIN;
    return st->arr[st->top];
}

bool pop(stack* st){
    if(st->top == -1) return false;
    st->top--;
    if(st->capacity > 4 && (st) < st->capacity/4){
        st->capacity/=2;
        st->arr = (int*)realloc(st->arr, st->capacity);
    }
}

int main(){

    return 0;
}