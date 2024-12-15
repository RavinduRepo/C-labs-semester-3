#include<stdio.h>

int main(){

    double Fahrenheit, Centigrade;

    printf("Input a temperature (in Fahrenheit): ");
    scanf("%lf", &Fahrenheit);

    Centigrade = 5.0/9.0 * (Fahrenheit - 32);

    printf("%.4lf degrees Centigrade.\n" , Centigrade);


    return 0;
}