#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *coeffs;
} polynomial;

polynomial *generate_polynomial(int size)
{
    polynomial *ans = (polynomial *)malloc(sizeof(polynomial));
    if (!ans)
        return NULL;
    ans->coeffs = (int *)calloc(size, sizeof(int));
    if (!ans->coeffs)
    {
        free(ans);
        return NULL;
    }
    ans->size = size;
    return ans;
}

void display_polynomial(polynomial *p)
{
    for (int i = p->size - 1; i > 0; i--)
    {
        printf("%dx", p->coeffs[i]);
        if (i > 1)
            printf("%d", i);
        printf(" + ");
    }
    printf("%d", p->coeffs[0]);
}

polynomial *poly_addition(polynomial *p1, polynomial *p2)
{
    if (!p1 || !p2)
        return NULL;
    int sz = p1->size > p2->size ? p1->size : p2->size;
    polynomial *ans = generate_polynomial(sz);
    for (int i = 0; i < sz; i++)
    {
        if (i < p1->size)
            ans->coeffs[i] += p1->coeffs[i];
        if (i < p2->size)
            ans->coeffs[i] += p2->coeffs[i];
    }
    return ans;
}

polynomial *poly_multiplication(polynomial *p1, polynomial *p2)
{
    if (!p1 || !p2)
        return NULL;
    int sz = p1->size + p2->size - 1;
    polynomial *ans = generate_polynomial(sz);
    for (int i = 0; i < p1->size; i++)
    {
        for (int j = 0; j < p2->size; j++)
        {
            ans->coeffs[i + j] += p1->coeffs[i] * p2->coeffs[j];
        }
    }
    return ans;
}

polynomial *poly_division(polynomial *p1, polynomial *p2)
{
    if (!p1 || !p2 || p2->size == 0 || p2->coeffs[p2->size - 1] == 0)
        return NULL;
    int quotient_size = p1->size >= p2->size ? p1->size - p2->size + 1 : 1;
    polynomial *quotient = generate_polynomial(quotient_size);
    if (!quotient)
        return NULL;
    if (p1->size < p2->size)
        return quotient;

    polynomial *remainder = generate_polynomial(p1->size);
    if (!remainder)
    {
        free(quotient->coeffs);
        free(quotient);
        return NULL;
    }
    for (int i = 0; i < p1->size; i++)
        remainder->coeffs[i] = p1->coeffs[i];
    for (int i = p1->size - p2->size; i >= 0; i--)
    {
        int leading = remainder->coeffs[i + p2->size - 1];
        if (leading == 0)
            continue;
        quotient->coeffs[i] = leading / p2->coeffs[p2->size - 1];
        for (int j = 0; j < p2->size; j++)
            remainder->coeffs[i + j] -= quotient->coeffs[i] * p2->coeffs[j];
    }
    free(remainder->coeffs);
    free(remainder);
    return quotient;
}

int main()
{

    return 0;
}