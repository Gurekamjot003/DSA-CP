#include<stdio.h>
#include<stdlib.h>

struct term{
    int exp;
    int coef;
};

struct polynomial{
    int size;
    struct term terms[];
}; 

struct polynomial* generate_polynomial(int size){
    struct polynomial* ans = (struct polynomial*)(malloc(sizeof(struct polynomial)));
}

struct polynomial* poly_addition(struct polynomial* p1, struct polynomial*p2)
{
    int ptr1 = 0, ptr2 = 0;
    struct polynomial* ans = (struct polynomial*)(malloc(sizeof(polynomial)))
    while(ptr1<p1->size && ptr2<p2->size){
        struct term t1 = p1->terms[ptr1];
        struct term t2 = p2->terms[ptr2];
        if(t1.exp < t2.exp){

        }
    }
}


int main(){

    return 0;
}