#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to print the current state of the array
void printArray(const std::vector<int>& levelSum) {
    for (int num : levelSum) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Function to partition the array
int partition(std::vector<int>& levelSum, int l, int r) {
    // Select a random pivot
    int pivotIndex = rand() % (r - l + 1) + l;
    
    // Swap pivot with the last element
    std::swap(levelSum[pivotIndex], levelSum[r]);
    std::cout << "Pivot chosen: " << levelSum[r] << " (Index: " << r << ")" << std::endl;
    std::cout << "Array after swapping pivot with last element: ";
    printArray(levelSum);

    int newPivot = l;

    // Partitioning process
    for (int i = l; i < r; i++) {
        if (levelSum[i] < levelSum[r]) {
            std::cout << "Swapping " << levelSum[i] << " with " << levelSum[newPivot] << std::endl;
            std::swap(levelSum[i], levelSum[newPivot]);
            newPivot++;
        }
        std::cout << "Array state after checking element " << levelSum[i] << ": ";
        printArray(levelSum);
    }

    // Place the pivot in its correct position
    std::swap(levelSum[newPivot], levelSum[r]);
    std::cout << "Placing pivot " << levelSum[newPivot] << " in correct position." << std::endl;
    std::cout << "Array after placing pivot: ";
    printArray(levelSum);

    return newPivot;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Example usage
    std::vector<int> levelSum = {10, 7, 8, 9, 1, 5};
    int n = levelSum.size();

    std::cout << "Initial Array: ";
    printArray(levelSum);
    
    int pivotIndex = partition(levelSum, 0, n - 1);
    
    std::cout << "Final Pivot Index: " << pivotIndex << std::endl;
    std::cout << "Array after partitioning: ";
    printArray(levelSum);

    return 0;
}
