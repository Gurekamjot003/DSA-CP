#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element

using namespace std;

// A utility function to get the maximum value in arr[]
int getMax(const vector<int>& arr) {
    int max_val = arr[0];
    for (int x : arr) {
        if (x > max_val) {
            max_val = x;
        }
    }
    return max_val;
}

// A function to do counting sort of arr[] according to the digit
// represented by 'exp'.
// exp is 10^i where i is current digit number
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    vector<int> count(10, 0); // count array for digits 0-9

    // Store count of occurrences in count[]
    // (arr[i] / exp) % 10 gives the digit at the current 'exp' place
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position
    // of this digit in output[]
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    // Iterate from the end to maintain stability
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted
    // numbers according to current digit
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// The main function to that sorts arr[] of size n using Radix Sort
// Time Complexity: O(N * K) where N is the number of elements and K is the maximum number of digits
// Space Complexity: O(N + B) where B is the base (10 for decimal numbers)
void radixSort(vector<int>& arr) {
    // Find the maximum number to know number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

// Function to print the elements of a vector
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Unsorted array
    vector<int> arr1 = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array 1: ";
    printArray(arr1);
    radixSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Original array 2: ";
    printArray(arr2);
    radixSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Array with duplicate elements
    vector<int> arr3 = {12, 11, 13, 5, 6, 7, 12, 11};
    cout << "Original array 3: ";
    printArray(arr3);
    radixSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Empty array
    vector<int> arr4 = {};
    cout << "Original array 4: ";
    printArray(arr4);
    radixSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Single element array
    vector<int> arr5 = {42};
    cout << "Original array 5: ";
    printArray(arr5);
    radixSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    cout << endl;

    // Example 6: Array with negative numbers (Radix sort typically for non-negative)
    // For negative numbers, a common approach is to separate them, sort positive,
    // sort absolute values of negative, then merge.
    // This implementation assumes non-negative integers.
    // vector<int> arr6 = {-170, 45, -75, 90, 802, -24, 2, 66};
    // cout << "Original array 6: ";
    // printArray(arr6);
    // radixSort(arr6); // This will not work correctly for negative numbers as implemented
    // cout << "Sorted array 6: ";
    // printArray(arr6);

    return 0;
}
