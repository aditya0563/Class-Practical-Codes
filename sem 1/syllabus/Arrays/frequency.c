#include <stdio.h>
int main() {
    int n, num, count = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to find its frequency: ");
    scanf("%d", &num);

    for(int i = 0; i < n; ++i) {
        if(arr[i] == num) {
            count++;
        }
    }
    printf("Frequency of %d in the array is: %d\n", num, count);
    return 0;
}
