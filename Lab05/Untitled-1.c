#include<stdio.h>
int main(){
    char x[50];
    char y[50];
    //printf("Enter the word: ");
    scanf(" %s",x);
    int i;
    int count=0;
    for (i=0; x[i]!='\0'; i++){
        count++;
    }
    int z=count;
    for(int j=0;j<count; j++){
        y[j]=x[z-1];
        z--;
    }
    int ispalindrome=1;
    for(int l=0; l<count;l++){
        if(y[l]!=x[l]){
            ispalindrome=0;
        }
    }
    if (ispalindrome){
        printf("The string is a palindrome.");
    }else{
        printf("The string is not  a palindrome.");
    }

    
    return 0;
}

