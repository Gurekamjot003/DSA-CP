#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right, *parent;
} Node;