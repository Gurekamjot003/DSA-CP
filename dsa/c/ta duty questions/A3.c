#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    printf("%5d\n", x);
    printf("%8d\n", x);
    printf("%-8d\n", x);
    printf("%05d\n", x);

    return 0;
}