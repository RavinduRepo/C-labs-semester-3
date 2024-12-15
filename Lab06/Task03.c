#include <stdio.h>

int ShiftRight (int ch){
    int shifted;
    //capital letters
    if (65 <= ch && ch < 90){
        shifted = ch + 1;
    }
    else if (ch == 90){
        shifted = 65;
    }
    //simple letters
    else if (97 <= ch && ch < 122){
        shifted = ch + 1;
    } 
    else if (ch == 122){
        shifted = 97;
    }
    else {
        shifted = ch;
    }
    return shifted;
}

int ShiftLeft (int ch){
    int shifted;
    //capital letters
    if (65 < ch && ch <= 90){
        shifted = ch - 1;
    }
    else if (ch == 65){
        shifted = 90;
    }
    //simple letters
    else if (97 < ch && ch <= 122){
        shifted = ch - 1;
    } 
    else if (ch == 97){
        shifted = 122;
    }
    else {
        shifted = ch;
    }
    return shifted;
}

int main(){

    char letter;

    printf("Enter a character: ");
    scanf(" %c", &letter);
    printf("Original character: %c\n", letter);
    printf("Rotated right: %c\n", ShiftRight(letter));
    printf("Rotated left: %c\n", ShiftLeft(letter));
    



    return 0;
}