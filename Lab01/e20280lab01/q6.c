#include<stdio.h>

int main(){

    int number_of_days;
    int years,  months, days;

    printf("Number of days: ");
    scanf("%d", &number_of_days);


    years = number_of_days / 365;
    months = (number_of_days - years * 365) / 30;
    days = (number_of_days - years * 365) - months * 30;

    printf("Years: %d, Months: %d, Days: %d\n" , years, months, days);


    return 0;
}