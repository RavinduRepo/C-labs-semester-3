/**
 * C program to count frequency of each character in a string
 */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    int i, len;
    int freq[26];

    /* Input string from user */
    printf("Enter any string: ");
    gets(str);

    len = strlen(str);

    /* Initialize frequency of each character to 0 */
    for(i=0; i<26; i++)
    {
        freq[i] = 0;
    }


    /* Find total number of occurrences of each character */
    for(i=0; i<len; i++)
    {
        /* If the current character is lowercase alphabet */
        if(str[i]>='a' && str[i]<='z')
        {
            freq[str[i] - 'a']++;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            freq[str[i] - 'A']++;
        }
    }

    /* Print the frequency of all characters in the string */
    printf("\nFrequency of all characters in the given string: \n");
    for(i=0; i<26; i++)
    {
        /* If current character exists in given string */
        if(freq[i] != 0)
        {
            printf("'%c' = %d\n", (i + 97), freq[i]);
        }
    }

    return 0;
}