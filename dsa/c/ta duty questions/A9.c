#include <stdio.h>

// Define the enum for letter grades
// By default, F=0, D=1, C=2, B=3, A=4
typedef enum {
    GRADE_F,
    GRADE_D,
    GRADE_C,
    GRADE_B,
    GRADE_A
} LetterGrade;

int main() {
    float marks[5];
    float total_obtained = 0.0;
    float max_possible_marks = 500.0; // Assuming each student's exam is out of 100
    float percentage;
    LetterGrade final_grade;

    printf("Enter marks for 5 students (out of 100 each):\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        if (scanf("%f", &marks[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
        total_obtained += marks[i];
    }

    // Calculate overall percentage
    percentage = (total_obtained / max_possible_marks) * 100.0;

    // Decide letter grade using ENUM states based on standard criteria
    if (percentage >= 90.0) {
        final_grade = GRADE_A;
    } else if (percentage >= 80.0) {
        final_grade = GRADE_B;
    } else if (percentage >= 70.0) {
        final_grade = GRADE_C;
    } else if (percentage >= 60.0) {
        final_grade = GRADE_D;
    } else {
        final_grade = GRADE_F;
    }

    // Displaying Results
    printf("\n--- Performance Summary ---\n");
    printf("Total Marks Obtained: %.2f / %.2f\n", total_obtained, max_possible_marks);
    printf("Aggregate Percentage: %.2f%%\n", percentage);
    
    // Print corresponding letter grade by checking the enum value
    printf("Final Letter Grade  : ");
    switch (final_grade) {
        case GRADE_A: printf("A\n"); break;
        case GRADE_B: printf("B\n"); break;
        case GRADE_C: printf("C\n"); break;
        case GRADE_D: printf("D\n"); break;
        case GRADE_F: printf("F\n"); break;
    }

    return 0;
}
