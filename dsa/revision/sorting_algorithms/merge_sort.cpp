#include <iostream>
#include <vector>
#include <algorithm> // For std::merge

using namespace std;

// Function to merge two sorted subarrays
// arr: The original array
// left: Starting index of the first subarray
// mid: Ending index of the first subarray (and mid+1 is start of second)
// right: Ending index of the second subarray
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the first subarray
    int n2 = right - mid;    // Size of the second subarray

    // Create temporary arrays to hold the two subarrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
// arr: The array to be sorted
// left: Starting index
// right: Ending index
// stable
// Time Complexity
//   - Average Case: O(N log N)
//   - Worst Case: O(N log N)
//   - Best Case: O(N log N)
// Space Complexity: O(N) (due to temporary arrays used in merge function)
void mergeSort(vector<int>& arr, int left, int right) {
    // Base case: if the subarray has 0 or 1 element, it's already sorted
    if (left >= right) {
        return;
    }

    // Find the middle point to divide the array into two halves
    int mid = left + (right - left) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
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
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    cout << "Original array 1: ";
    printArray(arr1);
    mergeSort(arr1, 0, arr1.size() - 1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Original array 2: ";
    printArray(arr2);
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Array with duplicate elements
    vector<int> arr3 = {5, 2, 8, 2, 5, 1};
    cout << "Original array 3: ";
    printArray(arr3);
    mergeSort(arr3, 0, arr3.size() - 1);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Empty array
    vector<int> arr4 = {};
    cout << "Original array 4: ";
    printArray(arr4);
    mergeSort(arr4, 0, arr4.size() - 1);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Single element array
    vector<int> arr5 = {42};
    cout << "Original array 5: ";
    printArray(arr5);
    mergeSort(arr5, 0, arr5.size() - 1);
    cout << "Sorted array 5: ";
    printArray(arr5);

    return 0;
}
