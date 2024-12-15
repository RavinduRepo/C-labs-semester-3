#include<stdio.h>

int main(){

    float float1, float2, sum, dif;
    printf("Enter the first number: ");
    scanf("%f", &float1);

    printf("Enter the second number: ");
    scanf("%f", &float2);

    sum = float1 + float2;
    dif = float1 - float2;

    printf("%f + %f = %f\n" , float1, float2, sum);
    printf("%f - %f = %f\n" , float1, float2, dif);

    return 0;
}