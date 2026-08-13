#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Selection Sort
// Unstable
// Time Complexity: O(N^2) in all cases (best, average, worst)
// Space Complexity: O(1)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted subarray
        // This places the minimum element at its correct sorted position
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
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
    vector<int> arr1 = {64, 25, 12, 22, 11};
    cout << "Original array 1: ";
    printArray(arr1);
    selectionSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original array 2: ";
    printArray(arr2);
    selectionSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Array with duplicate elements
    vector<int> arr3 = {5, 2, 8, 2, 5, 1};
    cout << "Original array 3: ";
    printArray(arr3);
    selectionSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Empty array
    vector<int> arr4 = {};
    cout << "Original array 4: ";
    printArray(arr4);
    selectionSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Single element array
    vector<int> arr5 = {42};
    cout << "Original array 5: ";
    printArray(arr5);
    selectionSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    return 0;
}
