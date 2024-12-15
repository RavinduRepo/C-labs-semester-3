#include <stdio.h>

int main(){
    int num, start , end, error = 0;


    //get input number
    scanf("%d", &num);

    //get the range for the table
    scanf("%d %d", &start, &end);

    if(num <= 0 && start >= end){
        error = 1;
        printf("Invalid Number and Invalid Range");
    }
    else if(num <= 0){
        error = 1;
        printf("Invalid Number");
    }
    else if(start >= end || start < 0 || end < 0){
        error = 1;
        printf("Invalid Range");
    }



    if(!error){
        //print the output
        printf("Multiplication table for %d (%d to %d):\n", num, start, end);

        for (int i = start ; i <= end ; i++){
            printf("%d x %d = %d \n", num, i, (num * i));
        }
    }
    return 0;
}
