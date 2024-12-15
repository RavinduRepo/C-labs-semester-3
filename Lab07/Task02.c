#include<stdio.h>
#include<string.h>

int isPal(char str[],int i, int len);

int main(){
    char str[200];
    gets(str);
    int len = strlen(str);
    if (isPal(str, 0, len)){
        printf("The string is a palindrome.\n");
    }
    else{
        printf("The string is not a palindrome.\n");
    }
    return 0;
}
int isPal(char str[],int i, int len){
    if (i == len/2){
        return 1;
    }
    else if (str[len  - i - 1] == str[i]){
        return isPal(str,i + 1, len);
    }
    else {
        return 0;
    }

}