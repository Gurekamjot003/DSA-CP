#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cmath>     // For std::floor

using namespace std;

// Function to perform Bucket Sort
// stable
// Time Complexity:
//   - Average Case: O(N + K) where N is the number of elements and K is the number of buckets.
//     This assumes elements are uniformly distributed.
//   - Worst Case: O(N^2) if all elements fall into a single bucket (e.g., not uniformly distributed)
//     and an O(N^2) sorting algorithm (like insertion sort) is used for buckets.
// Space Complexity: O(N + K) for storing buckets and elements.
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    if (n <= 1) {
        return; // Already sorted or nothing to sort
    }

    // 1. Create n empty buckets (or a suitable number of buckets based on range/distribution)
    // Here, we assume input elements are in the range [0, 1) for simplicity.
    // If the range is different, scaling is needed.
    vector<vector<float>> buckets(n);

    // 2. Put array elements into different buckets
    // For elements in [0, 1), multiply by n to get an index for the bucket.
    // E.g., 0.1 * 10 = 1 (bucket index 1), 0.9 * 10 = 9 (bucket index 9)
    for (int i = 0; i < n; ++i) {
        int bucket_index = floor(n * arr[i]); // Calculate bucket index
        buckets[bucket_index].push_back(arr[i]); // Add element to the corresponding bucket
    }

    // 3. Sort individual buckets
    // Use a stable sorting algorithm (like insertion sort or std::sort) for each bucket.
    // std::sort is typically IntroSort (hybrid of QuickSort, HeapSort, InsertionSort),
    // which is efficient for various data distributions.
    for (int i = 0; i < n; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

// Function to print the elements of a vector
void printArray(const vector<float>& arr) {
    for (float x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Unsorted array of floats (elements between 0.0 and 1.0)
    vector<float> arr1 = {0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f};
    cout << "Original array 1: ";
    printArray(arr1);
    bucketSort(arr1);
    cout << "Sorted array 1: ";
    printArray(arr1);

    cout << endl;

    // Example 2: Another unsorted array
    vector<float> arr2 = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};
    cout << "Original array 2: ";
    printArray(arr2);
    bucketSort(arr2);
    cout << "Sorted array 2: ";
    printArray(arr2);

    cout << endl;

    // Example 3: Empty array
    vector<float> arr3 = {};
    cout << "Original array 3: ";
    printArray(arr3);
    bucketSort(arr3);
    cout << "Sorted array 3: ";
    printArray(arr3);

    cout << endl;

    // Example 4: Single element array
    vector<float> arr4 = {0.5f};
    cout << "Original array 4: ";
    printArray(arr4);
    bucketSort(arr4);
    cout << "Sorted array 4: ";
    printArray(arr4);

    cout << endl;

    // Example 5: Already sorted array
    vector<float> arr5 = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
    cout << "Original array 5: ";
    printArray(arr5);
    bucketSort(arr5);
    cout << "Sorted array 5: ";
    printArray(arr5);

    return 0;
}
