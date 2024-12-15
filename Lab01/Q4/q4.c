#include<stdio.h>

int main(){

    float number_of_Items;
    float item_Price, total;

    printf("Number of items: ");
    scanf("%f", &number_of_Items);

    printf("Price of one item in Rs: ");
    scanf("%f", &item_Price);

    total = number_of_Items * item_Price;

    printf("Total cost in Rs: %.2f" , total);


    return 0;
}