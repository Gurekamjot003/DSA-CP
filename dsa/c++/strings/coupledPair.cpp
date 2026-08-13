#include <iostream>
#include <string.h>
using namespace std;

bool containsPair(int number, int pair) {
    char numStr[20]; // Assuming the number has at most 20 digits
    char pairStr[3]; // A pair of two digits and a null terminator

    itoa(number, numStr, 10); // Convert integer to string
    itoa(pair, pairStr, 10); // Convert pair to string

    // Check if the pair appears in the number as a substring
    return strstr(numStr, pairStr) != NULL;
}

int main() {
    int numbers[5];
    int pair;

    cout << "Enter a pair of two digits (e.g., 46): ";
    cin >> pair;

    cout << "Enter 5 integer numbers:" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    cout << "Numbers containing the pair " << pair << ":" << endl;

    for (int i = 0; i < 5; ++i) {
        if (containsPair(numbers[i], pair)) {
            cout << numbers[i] << endl;
        }
    }

    return 0;
}