#include<stdio.h>

int main(){

    int  int1, int2;

    printf("Enter two numbers(seperate with space): ");
    scanf("%d %d", &int1, &int2);

    int1 = int1 + int2;
    int2 = int1 - int2;
    int1 = int1 - int2;

    printf("Numbers after swapping: %d %d\n" , int1, int2);


    return 0;
}