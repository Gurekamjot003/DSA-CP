#include<stdio.h>
#include<stdlib.h>



typedef struct {
    int size;
    int* coeffs;
} polynomial;

polynomial* generate_polynomial(int size){
    polynomial* ans = (polynomial*)malloc(sizeof(polynomial));
    ans->coeffs = (int*)malloc(sizeof(int)*size);
    ans->size = size;
    return ans;
}

void display_polynomial(polynomial* p){
    for(int i = p->size-1; i>0; i--){
        printf("%dx",p->coeffs[i]);
        if(i>1) printf("%d",i);
        printf(" + ");
    }
    printf("%d", p->coeffs[0]);
}

polynomial* poly_addition(polynomial* p1, polynomial*p2)
{
    int sz = max(p1->size, p2->size);
    polynomial* ans = generate_polynomial(sz);
    for(int i = 0; i<sz; i++){
        if(i<p1->size) ans->coeffs[i] += p1->coeffs[i];
        if(i<p2->size) ans->coeffs[i] += p2->coeffs[i];
    }
    return ans;
}

polynomial* poly_multiplication(polynomial* p1, polynomial* p2){
    int sz = p1->size + p2->size - 1;
    polynomial* ans = generate_polynomial(sz);
    for(int i = 0; i<p1->size; i++){
        for(int j = 0; j<p2->size; j++){
            ans->coeffs[i+j] += p1->coeffs[i] + p2->coeffs[j];
        }
    }
    return ans;
}

polynomial* poly_division(polynomial* p1, polynomial* p2){
    
}


int main(){

    return 0;
}