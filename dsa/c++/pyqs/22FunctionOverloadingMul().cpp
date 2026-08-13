//write a c++program to multiply two list of numbers as well as to multiply two 3x3 matrices by passing both the  array to a function name mul() using function overloading

#include<iostream>
using namespace std;

class Multiplication {
public:
    // Function to multiply two lists of numbers
    void mul(int arr1[], int size1, int arr2[], int size2) {
        if (size1 != size2) {
            cout << "Lists must be of the same size for multiplication." << endl;
            return;
        }

        int result = 0;
        for (int i = 0; i < size1; i++) {
            result += arr1[i] * arr2[i];
        }

        cout << "Result of multiplying two lists of numbers: " << result << endl;
    }

    // Function to multiply two 3x3 matrices
    void mul(int mat1[3][3], int mat2[3][3], int resultMat[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                resultMat[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    resultMat[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        cout << "Result of multiplying two matrices:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << resultMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Multiplication obj;

    // Multiply two lists of numbers
    int list1[] = {1, 2, 3};
    int list2[] = {4, 5, 6};
    obj.mul(list1, 3, list2, 3);

    cout << endl;

    // Multiply two 3x3 matrices
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int resultMatrix[3][3];
    obj.mul(matrix1, matrix2, resultMatrix);

    return 0;
}
