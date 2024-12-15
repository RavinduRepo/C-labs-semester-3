#include <stdio.h>


double sin(int angle, int terms);

int fact(int num);

int power(int num, int p);

int main() {
    int angle, terms;

    // Taking input for the angle
    printf("Enter the angle: ");
    scanf("%d", &angle);

    // Taking input for the terms
    printf("Enter the terms: ");
    scanf("%d", &terms);
    
    sin(angle, terms);
    
    return 0;
}


double sin(int angle, int terms){
    
    
    
    
}


int fact(int num){
    if (num == 0){
        return 1;
    }else{
    return num * fact(num - 1);
    }
}

int power(int num.int p){
    
    
    
}








