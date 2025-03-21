#include <stdio.h>
int printEvenNumbers(int n){
    printf("Even numbers before %d are:\n", n);
    for (int i = 2; i < n; i += 2){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
int printOddNumbers(int n){
    printf("Odd numbers before %d are:\n", n);
    for (int i = 1; i < n; i += 2){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
int main(){
    int n;
    char choosed; 
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("1. Odd---> O\t 2. Even---> E \n What type of numbers do you want: ");
    scanf(" %c",&choosed);
    if(choosed=='O'){
        printOddNumbers(n);
    }else if (choosed=='E'){
        printEvenNumbers(n);
    }else{
        printf("The inputted character is incorrect.");
    }
    return 0;
}