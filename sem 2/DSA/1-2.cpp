#include <iostream>
using namespace std;

// Function to dynamically allocate a 2D array
int** create2DArray(int rows, int cols) {
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

// Function to deallocate the 2D array
void delete2DArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

// Function to perform matrix addition
int** addMatrices(int** A, int** B, int rows, int cols) {
    int** C = create2DArray(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to perform matrix transpose
int** transposeMatrix(int** A, int rows, int cols) {
    int** T = create2DArray(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            T[j][i] = A[i][j];
        }
    }
    return T;
}

// Function to print a 2D array
void print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 3, cols = 3;

    // Create and initialize two matrices
    int** A = create2DArray(rows, cols);
    int** B = create2DArray(rows, cols);

    // Example initialization (can be replaced with user input)
    int counter = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            A[i][j] = counter;
            B[i][j] = counter * 2;
            ++counter;
        }
    }

    // Perform matrix addition
    int** C = addMatrices(A, B, rows, cols);
    cout << "Matrix A:" << endl;
    print2DArray(A, rows, cols);
    cout << "Matrix B:" << endl;
    print2DArray(B, rows, cols);
    cout << "Matrix C (A + B):" << endl;
    print2DArray(C, rows, cols);

    // Perform matrix transpose
    int** T = transposeMatrix(A, rows, cols);
    cout << "Transpose of Matrix A:" << endl;
    print2DArray(T, cols, rows);

    // Deallocate memory
    delete2DArray(A, rows);
    delete2DArray(B, rows);
    delete2DArray(C, rows);
    delete2DArray(T, cols);

    return 0;
}
