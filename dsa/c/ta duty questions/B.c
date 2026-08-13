#include <stdio.h>
int main()
{
    for (int i = 0; i < 5; i++)
    {

        int marks;
        scanf("%d", &marks);
        if (marks < 0 || marks > 100)
        {
            printf("wrong input");
        }
        if (marks >= 90)
            printf("A");
        else if (marks >= 75)
            printf("B");
        else if (marks >= 60)
            printf("C");
        else if (marks >= 40)
            printf("D");
        else
            printf("Fail");
        printf("\n");
    }
    return 0;
}