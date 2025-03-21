#include <stdio.h>
int main() {
    int arr[100], size, i, toSearch, found;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &toSearch);
    found = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] == toSearch) {
            found = 1;
            break;
        }
    }
    if(found == 1) {
        printf("%d is found at position %d\n", toSearch, i + 1);
    } else {
        printf("%d is not found in the array\n", toSearch);
    }

    return 0;
}