#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to heapify a subtree rooted with node i (an index in arr[])
// n is size of heap
// unstable
// Time Complexity: O(log N)
// Space Complexity: O(1)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
// arr: The array to be sorted
// Time Complexity:
//   - Best, Average, Worst Case: O(N log N)
// Space Complexity: O(1) (in-place sorting)
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    // Start from the last non-leaf node and go up to the root
    // The last non-leaf node is at index (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; --i) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    vector<int> arr2 = {4, 10, 3, 5, 1};
    cout << "Original array 2: ";
    printArray(arr2);

    heapSort(arr2);

    cout << "Sorted array 2: ";
    printArray(arr2);

    return 0;
}