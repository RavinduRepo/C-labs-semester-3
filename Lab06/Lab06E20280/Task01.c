#include<stdio.h>

int countOccurrences (char str[], char target){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == target){
            count++;
        }
    }

    return count;
}


int main(){
    char str[90], target;

    printf("Enter sentence/paragraph: ");
    fgets(str, 90, stdin);

    printf("Enter the character: ");
    scanf(" %c", &target);

    // printf("%s : %c", str, target);

    printf("The character '%c' occurs %d times in the input.", target, countOccurrences(str, target));





    return 0;
}