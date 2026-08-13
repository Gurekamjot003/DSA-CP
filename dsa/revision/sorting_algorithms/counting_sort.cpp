#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element, std::min_element

using namespace std;

// Function to perform Counting Sort
// stable
// Time Complexity: O(N + K) where N is the number of elements and K is the range of input
// Space Complexity: O(K)
void countingSort(vector<int>& arr) {
    int n = arr.size();

    if (n == 0) {
        return; // Nothing to sort for an empty array
    }

    // Find the maximum and minimum elements to determine the range (K)
    int max_val = arr[0];
    int min_val = arr[0];
    for (int x : arr) {
        if (x > max_val) {
            max_val = x;
        }
        if (x < min_val) {
            min_val = x;
        }
    }

    // Calculate the range of values (K)
    int range = max_val - min_val + 1;

    // Create a count array to store count of individual characters
    // Initialize all counts to 0
    vector<int> count(range, 0);

    // Store count of each element
    // The index in the count array corresponds to (element_value - min_val)
    for (int x : arr) {
        count[x - min_val]++;
    }

    // Modify the count array such that each element at each index
    // stores the sum of previous counts. This helps in determining
    // the position of each element in the output array.
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(n);

    // Build the output array
    // Iterate from the end of the original array to maintain stability
    // (i.e., elements with the same value appear in the same order as in the input)
    for (int i = n - 1; i >= 0; --i) {
        // Determine the correct position for arr[i] in the output array
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--; // Decrement count for the current element
    }

    // Copy the sorted elements from output array to original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
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
    // Example 1: Unsorted array with positive numbers
    vector<int> arr1 = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array 1: ";
    printArray(arr1);
    countingSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Array with negative numbers (requires adjustment for min_val)
    // Note: Counting sort is typically for non-negative integers.
    // This implementation handles negative numbers by shifting the range.
    vector<int> arr2 = {-5, -10, 0, -3, 8, 5, -1};
    cout << "Original array 2: ";
    printArray(arr2);
    countingSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Already sorted array
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Original array 3: ";
    printArray(arr3);
    countingSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Array with all same elements
    vector<int> arr4 = {7, 7, 7, 7, 7};
    cout << "Original array 4: ";
    printArray(arr4);
    countingSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Empty array
    vector<int> arr5 = {};
    cout << "Original array 5: ";
    printArray(arr5);
    countingSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    cout << endl;

    // Example 6: Single element array
    vector<int> arr6 = {42};
    cout << "Original array 6: ";
    printArray(arr6);
    countingSort(arr6);
    cout << "Sorted array 6: ";
    printArray(arr6);

    return 0;
}
