#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Insertion Sort
// stable
// Time Complexity: O(N^2) in worst and average case, O(N) in best case (already sorted array)
// Space Complexity: O(1)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    // Start from the second element (index 1) as the first element (index 0) is considered sorted
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // The element to be inserted into the sorted subarray
        int j = i - 1;    // Index of the last element in the sorted subarray

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;           // Move to the left in the sorted subarray
        }
        arr[j + 1] = key; // Place the key at its correct position in the sorted subarray
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
    vector<int> arr1 = {12, 11, 13, 5, 6};
    cout << "Original array 1: ";
    printArray(arr1);
    insertionSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original array 2: ";
    printArray(arr2);
    insertionSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Array with duplicate elements
    vector<int> arr3 = {5, 2, 8, 5, 1, 9, 2};
    cout << "Original array 3: ";
    printArray(arr3);
    insertionSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Empty array
    vector<int> arr4 = {};
    cout << "Original array 4: ";
    printArray(arr4);
    insertionSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Single element array
    vector<int> arr5 = {42};
    cout << "Original array 5: ";
    printArray(arr5);
    insertionSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    return 0;
}