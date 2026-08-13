#include <stdio.h>

int main() {
    int num1, num2, num3;
    int sum;
    float avg_without_casting;
    float avg_with_casting;

    printf("Enter three integers (separated by spaces): ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    // Calculate total sum
    sum = num1 + num2 + num3;

    // 1. Without type casting (Integer Division)
    // Both 'sum' and '3' are integers, so fractional parts are permanently lost here
    avg_without_casting = sum / 3;

    // 2. With explicit type casting (Floating-point Division)
    // (float) explicitly forces 'sum' into a float before division occurs
    avg_with_casting = (float)sum / 3;

    // Displaying the results
    printf("\n--- Results ---\n");
    printf("Sum: %d\n", sum);
    printf("Average without type casting : %.2f\n", avg_without_casting);
    printf("Average with explicit casting : %.2f\n", avg_with_casting);

    return 0;
}
