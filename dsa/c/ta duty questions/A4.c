#include <stdio.h>

int main() {
    int roll_no;
    char name[50];
    float cgpa;

    printf("Enter student record (Format: Roll,Name,CGPA): ");

    // The single scanf statement handling the comma-separated format safely
    // %49[^,] reads up to 49 characters until it hits a comma, preventing buffer overflow
    if (scanf("%d,%49[^,],%f", &roll_no, name, &cgpa) == 3) {
        printf("\n--- Parsed Record ---\n");
        printf("Roll Number: %d\n", roll_no);
        printf("Name       : %s\n", name);
        printf("CGPA       : %.2f\n", cgpa);
    } else {
        printf("Error: Invalid input format. Please use 'Roll,Name,CGPA'\n");
    }

    return 0;
}
