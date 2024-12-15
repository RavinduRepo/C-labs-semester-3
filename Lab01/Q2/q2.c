#include<stdio.h>

int main(){

    int int1, int2, prod;
    printf("Enter the first number: ");
    scanf("%d", &int1);

    printf("Enter the second number: ");
    scanf("%d", &int2);

    prod = int1 * int2;

    printf("%d X %d = %d" , int1, int2, prod);

    return 0;
}