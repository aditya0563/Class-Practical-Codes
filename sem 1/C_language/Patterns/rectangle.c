#include <stdio.h>
int main(){
    int i,j,rows,cols;
    printf("no of rows:");
    scanf("%d",&rows);
    printf("no of columns:");
    scanf("%d",&cols);
    for(i=1;i<=rows;i++){
        for(j=1;j<=cols;j++){
            printf("*");
        }
        printf("\n");
    }
return 0;
}