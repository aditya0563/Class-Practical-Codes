#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum possible elements in the array

// Function to count the frequency of each element in the array
void countFrequency(int arr[], int n) {
    int freq[MAX] = {0}; // Initialize frequency array

    // Traverse the array and update the frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print the frequency of each element
    printf("Element Frequencies:\n");
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            printf("%d --> %d\n", i, freq[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Count the frequency of each element in the array
    countFrequency(arr, n);

    return 0;
}
