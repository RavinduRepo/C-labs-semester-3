#include<stdio.h>
char bin[65];
char *long2bin(long n);

int main()
{
    long number;
    printf("Enter the integer: ");
    scanf("%li", &number);
    printf("Binary representation of %d is %s", number, long2bin(number));
    return 0;
}

char *long2bin(long n)
{
    // static char bin[65];

    for (int i = 0; i < 64; i++)
    {
        if ((n >> (63 - i)) & 1){
            bin[i] = '1';
        }else{
            bin[i] = '0';
        }
    }
    bin[64] = '\0';
    return bin;
}


