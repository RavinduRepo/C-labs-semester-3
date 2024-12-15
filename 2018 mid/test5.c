#include <stdio.h>
char str[65];
char *long2bin(long n);

int main()
{
    char number[10], a[10];
    printf("Enter the integer: ");
    gets(number);
    // getchar();
    // printf("Enter the integer: ");
    gets(a);
    printf("%s \n%s", number, a);
    return 0;
}
