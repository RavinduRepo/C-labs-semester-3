#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int income,invalidInput = 0, done = 0; // (0) - false, (-1) - true
    float Tax = 0.0;
    char input[20];

    scanf("%s" , input);
    int length = strlen(input);
    for(int i = 0;  i < length; i++){
        if(!((input[i] == '0')||(input[i] == '1')||(input[i] == '2')||(input[i] == '3')||(input[i] == '4')||(input[i] == '5')||(input[i] == '6')||(input[i] == '7')||(input[i] == '8')||(input[i] == '9'))){
            invalidInput = -1;
        }
    }
    if(invalidInput == 0){
        income = atoi(input);

        if(income > (1200000/12)){
            for(int index = 1; (index <= 6) && (done != -1); index++){
                if((((income - 1200000/12) - (index) * 500000/12) <= 0) || index == 6){
                    Tax = Tax + (((float)income - 1200000/12) - ((float)index - 1) * 500000/12) * 0.06 * index;
                    done = -1;
                } else {
                    Tax = Tax + 2500 * index;
                }
            }
        } 
        printf("Total tax = %.2f LKR\n", Tax);
    } else{
        printf("%d", -1);
    }
    return 0;
}