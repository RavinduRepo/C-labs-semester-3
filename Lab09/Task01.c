#include<stdio.h>

void findStringLength(char *str, int *length);
void reverseTheString(char *str, int *length);

int main(){
    char str[100];
    int len = 0;
    gets(str);
    findStringLength(str, &len);
    reverseTheString(str, &len);
    printf("The length of the string is: %d\n", len);
    printf("The reversed string is: %s", str);
    return 0;
}

void reverseTheString(char *str, int *length){    
    for (int i = 0; i < *length / 2; i++){
        char s = str[i];
        str[i] = str[*length - 1 - i];
        str[*length - 1 - i] = s;
    }
}

void findStringLength(char *str, int *length){
    int i = 0;
    for (i; str[i] != '\0'; i++);
    *length = i;
}