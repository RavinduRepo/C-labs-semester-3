
#include<stdio.h>

int main(){

    long int input , negative = 0, error = 0, output[64], i = 0;

    if (!(scanf(" %li", &input))){
        error = 1;
    }

    if (input < 0){ // check if input is negative
        negative = 1;
    }
    if (!(error || negative)){ // if input is valid, convetes to binary
        if (input == 0){
            printf("%d", 0);
        }
        while (input > 0){ // store each value in output 
            output[i] = input % 2;
            input = input / 2;
            i++; // make a count of howmany digits are in the output
            }
        for (int j = i - 1; j >= 0; j--){ //print the output starting from the end to the biggening
            printf("%d", output[j]);
            }

        printf("\n");
    }
    else if (error){ //prints error msg
        printf("Invalid Input - Not a Number");
    }
    else if (negative){
        printf("Invalid Input - Negative Number");
    }

    return 0;
}