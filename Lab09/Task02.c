#include<stdio.h>

int squareValuesPassByValue(int a, int b);
int squareValuesPassByReference(int *a, int *b);

int main(){
    int a, b;
    scanf(" %d %d", &a, &b);

    printf("Values Before operations: %d, %d\n", a, b);
    printf("Before operations: %d, %d\n", a, b);
    printf("Value obtained by squareValuesPassByValue: %d\n", squareValuesPassByValue(a, b));
    printf("After squareValuesPassByValue: %d, %d\n", a, b);
    printf("Value obtained by squareValuesPassByReference: %d\n", squareValuesPassByReference(&a, &b));
    printf("After squareValuesPassByReference: %d, %d\n", a, b);

    return 0;
}

int squareValuesPassByValue(int a, int b){
    a = a * a;
    b = b * b;
    return a + b;
}

int squareValuesPassByReference(int *a, int *b){
    *a = (*a) * (*a);
    *b = (*b) * (*b);
    return *a + *b;
}