#include <stdio.h>

int main() {
    char name[100];
    int train_no;
    char date[15];
    char seat_no[15];
    float fare;

    printf("Enter Passenger Details (Format: Name,TrainNo,Date,SeatNo,Fare):\n");

    // %99[^,] reads up to 99 characters until it hits a comma
    // The literal commas in the format string match and discard the input commas
    if (scanf("%99[^,],%d,%14[^,],%14[^,],%f", name, &train_no, date, seat_no, &fare) == 5) {
        
        // Generate the ticket format precisely matching your example
        printf("\n=========================================\n");
        printf("RAILWAY TICKET\n");
        printf("=========================================\n");
        printf("Passenger : %s\n", name);
        printf("Train No. : %d\n", train_no);
        printf("Journey   : %s\n", date);
        printf("Seat No.  : %s\n", seat_no);
        printf("Fare      : Rs. %.2f\n", fare); // Formatted to exactly 2 decimal places
        printf("=========================================\n");

    } else {
        printf("Error: Invalid input format. Please check your commas and values.\n");
    }

    return 0;
}
