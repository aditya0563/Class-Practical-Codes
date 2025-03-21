#include <iostream>
#include <unordered_map>
using namespace std;

// Function to count the frequency of each element in the array
void countFrequency(int arr[], int n) {
    // Create an unordered_map to store the frequency of each element
    unordered_map<int, int> freqMap;

    // Traverse the array and update the frequency in the map
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Print the frequency of each element
    cout << "Element Frequencies:" << endl;
    for (const auto& pair : freqMap) {
        cout << pair.first << " --> " << pair.second << endl;
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Count the frequency of each element in the array
    countFrequency(arr, n);

    return 0;
}
