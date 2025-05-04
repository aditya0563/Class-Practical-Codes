#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Store the count of occurrences in count[]
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to reflect actual positions in output[]
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array back to arr[]
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }

    free(output);
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array (Radix Sort): ");
    printArray(arr, n);

    return 0;
}
