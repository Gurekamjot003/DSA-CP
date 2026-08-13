#include <stdio.h>

int main(){
    char name[50];
    int roll_no, age;
    float cgp;
    char grade;
    gets(name);
    // printf(name);
    scanf("%d", &roll_no);
    // printf("%d", roll_no);
    scanf("%d", &age);
    scanf("%f", &cgp);
    scanf(" %c", &grade);
    printf("Student info\n");
    printf("Name = %s\n", name);
    printf("Roll no = %d\n", roll_no);
    printf("Age = %d\n", age);
    printf("CGPA = %f\n", cgp);
    printf("grade = %c\n", grade);
    
    
    return 0;
}