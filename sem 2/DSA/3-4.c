#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a; // Store the value of *a in a temporary variable
    *a = *b;       // Assign the value of *b to *a
    *b = temp;     // Assign the temporary value to *b
}

// Function to generate a random pivot and partition the array
int partition(int arr[], int low, int high) {
    // Generate a random pivot index
    int randomIndex = low + rand() % (high - low + 1);
    // Swap the random pivot with the last element
    swap(&arr[randomIndex], &arr[high]);

    int pivot = arr[high]; // Pivot element (last element after swapping)
    int i = low - 1;       // Index for elements less than pivot

    // Iterate through the array from 'low' to 'high - 1'
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) { // If the current element is smaller than the pivot
            ++i;              // Move the index for smaller elements
            swap(&arr[i], &arr[j]); // Swap the smaller element into place
        }
    }
    // Place the pivot in the correct position
    swap(&arr[i + 1], &arr[high]);
    return i + 1; // Return the partition index
}

// Function to implement quick sort using recursion
void quickSort(int arr[], int low, int high) {
    if (low < high) { // Base case: if low < high
        int pi = partition(arr, low, high); // Get the partition index

        // Recursively sort the left subarray and right subarray
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // Move to the next line
}

int main() {
    srand(time(0)); // Seed the random number generator

    int arr[] = {10, 7, 8, 9, 1, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Sort the array using quicksort

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
