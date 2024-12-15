#include<stdio.h>

int main(){
    char input[255];


    while (1){

        printf("\nEnter a string: ");
        gets(input);

        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't' && input[4] == '\0'){
            break;
        }

        printf("Upper case string: ");
        for (int i = 0; input[i] != '\0'; i++){
            if (96 < (int)input[i] && (int)input[i] < 123){
                input[i] = (int)input[i] - 32;
            }
        printf("%c", input[i]);
        }
    }
    

    return 0;
}