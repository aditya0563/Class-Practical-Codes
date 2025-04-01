#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    int arr[] = {64, 25, 12, 22, 11}; // Initialize the array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n); // Sort the array using selection sort

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
