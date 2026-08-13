#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to partition the array around a pivot
// It places the pivot element at its correct sorted position
// and places all smaller elements to its left and all greater elements to its right.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; ++j) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap current element with the element at i
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot at its correct position
    return (i + 1); // Return the partitioning index
}

// Function to perform Quick Sort
// arr: The array to be sorted
// low: Starting index
// high: Ending index
// unstable
// Time Complexity:
//   - Average Case: O(N log N)
//   - Worst Case: O(N^2) (e.g., when array is already sorted or reverse sorted and pivot choice is always an extreme)
//   - Best Case: O(N log N)
// Space Complexity:
//   - Average Case: O(log N) (due to recursion stack)
//   - Worst Case: O(N) (due to recursion stack, if partitioning is highly unbalanced)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    cout << "Original array 1: ";
    printArray(arr1);
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original array 2: ";
    printArray(arr2);
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Array with duplicate elements
    vector<int> arr3 = {5, 2, 8, 2, 5, 1};
    cout << "Original array 3: ";
    printArray(arr3);
    quickSort(arr3, 0, arr3.size() - 1);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Empty array
    vector<int> arr4 = {};
    cout << "Original array 4: ";
    printArray(arr4);
    quickSort(arr4, 0, arr4.size() - 1);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Single element array
    vector<int> arr5 = {42};
    cout << "Original array 5: ";
    printArray(arr5);
    quickSort(arr5, 0, arr5.size() - 1);
    cout << "Sorted array 5: ";
    printArray(arr5);

    return 0;
}