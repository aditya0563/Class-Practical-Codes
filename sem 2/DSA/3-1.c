#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; // Place the key element in its correct position
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]); // Print each element in the array
    }
    printf("\n"); // Move to the next line after printing the array
}

int main() {
    int arr[] = {12, 11, 13, 5, 6}; // Initialize the array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n); // Sort the array using insertion sort

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
