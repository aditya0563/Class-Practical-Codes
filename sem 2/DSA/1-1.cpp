#include <iostream>
using namespace std;

// Function to insert an element at a specific position
void insertElement(int arr[], int& n, int element, int position) {
    if (position >= n || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    // Shift elements to the right to make space for the new element
    for (int i = n; i > position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    ++n;
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int& n, int position) {
    if (position >= n || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    // Shift elements to the left to fill the gap created by the deleted element
    for (int i = position; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;
}

// Function to update an element at a specific position
void updateElement(int arr[], int n, int element, int position) {
    if (position >= n || position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    arr[position] = element;
}

// Function to traverse and print the array elements
void traverseArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100]; // Declare an array of size 100
    int n = 0; // Current number of elements in the array

    // Insert elements
    insertElement(arr, n, 10, 0); // Insert 10 at position 0
    insertElement(arr, n, 20, 1); // Insert 20 at position 1
    insertElement(arr, n, 30, 2); // Insert 30 at position 2

    // Traverse array
    cout << "Array after insertion: ";
    traverseArray(arr, n);

    // Update element
    updateElement(arr, n, 25, 1); // Update position 1 with 25

    // Traverse array
    cout << "Array after updating: ";
    traverseArray(arr, n);

    // Delete element
    deleteElement(arr, n, 1); // Delete element at position 1

    // Traverse array
    cout << "Array after deletion: ";
    traverseArray(arr, n);

    return 0;
}
