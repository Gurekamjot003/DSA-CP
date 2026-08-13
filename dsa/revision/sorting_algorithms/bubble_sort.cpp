#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Bubble Sort
// stable sorting algorithm
// Time Complexity: O(N^2) in worst and average case, O(N) in best case (already sorted array)
// Space Complexity: O(1)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    // Outer loop for passes
    // In each pass, the largest unsorted element bubbles up to its correct position
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; // Flag to optimize: if no two elements are swapped in a pass, the array is sorted
        // Inner loop for comparisons and swaps
        // The inner loop runs up to n-1-i because the last 'i' elements are already sorted
        for (int j = 0; j < n - 1 - i; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in the wrong order 
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        // If no two elements were swapped by inner loop, then break
        // This means the array is already sorted
        if (!swapped) {
            break;
        }
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
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array 1: ";
    printArray(arr1);
    bubbleSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2:
    vector<int> arr2 = {5, 1, 4, 2, 8};
    cout << "Original array 2: ";
    printArray(arr2);
    bubbleSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Already sorted array (best case)
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Original array 3: ";
    printArray(arr3);
    bubbleSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Array with duplicate elements
    vector<int> arr4 = {5, 2, 8, 2, 5, 1};
    cout << "Original array 4: ";
    printArray(arr4);
    bubbleSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Empty array
    vector<int> arr5 = {};
    cout << "Original array 5: ";
    printArray(arr5);
    bubbleSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    cout << endl;

    // Example 6: Single element array
    vector<int> arr6 = {42};
    cout << "Original array 6: ";
    printArray(arr6);
    bubbleSort(arr6);
    cout << "Sorted array 6: ";
    printArray(arr6);

    return 0;
}
