#include<stdio.h>
int main(){
    float principal,rate,time,simple_intrest;
    printf("enter the principal amount:");
    scanf("%f",&principal);
    printf("enter the rate(in percentage):");
    scanf("%f",&rate);
    printf("enter the time(in years):");
    scanf("%f",&time);
    printf("the calculated simple intrest is:%f\n",(principal*rate*time)/100);
    return 0;
}
