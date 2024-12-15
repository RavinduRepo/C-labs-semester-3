#include <stdio.h>


int countOccurrences (char str[], char target){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == target){
            count++;
        }
    }

    return count;
}

int factorial (int n){
    int fac = n;
    if (n == 0){
        fac = 1;
        }
    if (n < 0){
        return 0;
    }
    
    for (int i = n - 1; i > 0; i--){
        fac *= i;
    }
    
    return fac;
}

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

void riddlersGame( char sentence[], char character, int choice ){
    int count = countOccurrences(sentence, character);
    int shift = (count != 0)? factorial(count)%26 : 0;
    int s = shift;
   
    //Right shift
    if (!choice){
        for (int i = 0; sentence[i] != '\0'; i++){
            for (s; s > 0; s--){
                sentence[i] = ShiftRight(sentence[i]);
            }
            s = shift;
        }
    }

    //Left shift
    if (choice){
        for (int i = 0; sentence[i] != '\0'; i++){
            for (s; s > 0; s--){
                sentence[i] = ShiftLeft(sentence[i]);
            }
            s = shift;
        }
    }

}
int main(){

    char str[90], target;
    int choice;
    //get paragraph input
    printf("Enter sentence/paragraph: ");
    fgets(str, 90, stdin);
    //get target letter input
    printf("Enter the character: ");
    scanf(" %c", &target);
    //get choice input
    printf("Enter a choice (0 or 1): ");
    scanf(" %d", &choice);

    riddlersGame(str, target, choice);

    //output
    printf("%s\n", str);



    return 0;
}