
#include<stdio.h>

int main(){
    char input[255];

    int rounds;

    scanf(" %d", &rounds);

    for (rounds; rounds > 0; rounds--){
   
        scanf(" %99[^\n]",input);

        // if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't' && input[4] == '\0'){
        //     break;
        // }

        // printf("Upper case string: ");
        for (int i = 0; input[i] != '\0'; i++){
            if ('a' <= input[i] && input[i] <= 'z'){
                input[i] = input[i] - 32;
            }
        printf("%c", input[i]);
        }
        printf("\n");
    }
    

    return 0;
}