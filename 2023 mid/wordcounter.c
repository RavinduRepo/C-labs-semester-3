#include<stdio.h>

int main(){
    char text[50];
    int words = 0;
    gets(text);
    for (int i = 0; text[i] !='\0'; i++){
        if (text[i]==' ' || text[i]=='\n' || text[i]=='\t')
            words++;
    }
    printf("%d", words+1);
    return 0;
}