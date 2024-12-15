#include<stdio.h>

int main(){

    long int input, digit, reverse = 0, negative = 0, error = 0;

    scanf(" %li", &input); // takes input


    // check if negative
    if (input < 0){
        input *= -1;
        negative = 1;
    }
//-1234
//-123400
//1000000003
//1286608618

//1234567890

//-1000000003
//-789552
//-100
    
    while (input > 0){
            if (reverse >= (2147483647 / 10)){
                error = 1;
                break;
            }
        digit = input % 10;
        reverse = 10 * reverse + digit;
        input = input / 10;
    }
    


    if (negative){
        reverse *= -1;
    }

    if (!error){
        printf("%li\n", reverse);
    } else{
        printf("Error: Overflow/Underflow Detected");
    }

    return 0;
}