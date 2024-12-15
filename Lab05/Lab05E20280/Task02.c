#include<stdio.h>

int main(){
    char input[255], check[255];
    int count = 0;
    int isPalindrome = 1;

    printf("\nEnter a sentence: ");
    gets(input);
    for (int i = 0; input[i] != '\0'; i++){
        if (96 < (int)input[i] && (int)input[i] < 123){ // make every letter capital
            input[i] = (int)input[i] - 32;
        }
         count++; //conts the num of letters in the word
    }
    int i = 0;
    for (count; count > 0; count--){
        check[i] = input[count - 1];
        i++;
    }
    for (int k = 0; input[k] != '\0'; k++){
        if (check[k] != input[k]){
            isPalindrome = 0;
        }
    }
    if (isPalindrome){
        printf("The string is a palindrome.\n");
    }
    else if (!isPalindrome){
        printf("The string is not a palindrome.\n");
    }
    return 0;
}