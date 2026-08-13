#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char x[100], ch[] = "0123456789"; // Define ch as a string
    cin >> x;

    for (int i = 0; ch[i] != '\0'; i++) { // Iterate through the digits 0 to 9
        bool isPresent = false;

        // Check if the digit ch[i] is present in the user-entered string
        for (int j = 0; x[j] != '\0'; j++) {
            if (ch[i] == x[j]) {
                isPresent = true;
                break;
            }
        }

        // If the digit is not present, print it
        if (!isPresent) {
            cout << ch[i];
        }
    }

    return 0;
}
