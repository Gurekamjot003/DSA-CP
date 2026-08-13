#include <stdio.h>

int main() {
    int roll_no;
    char grade;
    float cgpa;

    printf("Enter Roll Number, Grade, and CGPA (separated by spaces): ");

    // Reads all three values from a single line
    // Notice the crucial space right before %c
    if (scanf("%d %c %f", &roll_no, &grade, &cgpa) == 3) {
        
        printf("\n--- Displaying Values ---\n");
        printf("Roll Number : %d\n", roll_no);
        printf("Grade       : %c\n", grade);
        printf("CGPA        : %.2f\n", cgpa); // Formatted to 2 decimal places
        
    } else {
        printf("Error: Invalid input format. Please match: 101 A 8.75\n");
    }

    return 0;
}
