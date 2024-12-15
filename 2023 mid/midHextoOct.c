#include <stdio.h>

int main() {
    char str[100];
    char Oct[100];
    long long num;
    printf("Enter a number (will be treated as hexadecimal): ");
    scanf("%s", str);  // Read the input as a string
    sscanf(str, "%llx", &num);  // Convert the string to a hexadecimal number
    sprintf(Oct, "%llo", num);
    printf("Octal equivalent: %s\n", Oct);  // Print the number as octal
    return 0;
}
