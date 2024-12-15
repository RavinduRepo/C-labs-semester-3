#include <stdio.h>
char str[65];
char *long2bin(long n);

int main()
{
    long number;
    printf("Enter the integer: ");
    scanf("%li", &number);
    printf("Binary representation of %d is %s", number, long2bin(number));
    return 0;
}

char *long2bin(long n){
    long int bin[64];
    for(int i=63;i>=0;i--){
        str[i]=(n&1) + '0';
        n>>=1;
    }
    str[64]='\0';
    return str;
        
}
