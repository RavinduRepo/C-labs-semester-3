#include<stdio.h>
#include <string.h>

int main(){
    int income, done = 0, validInput = 0; // 0 - still calculating , -1 - done calculating
    float Tax = 0.0;
    char get[20];

    // printf("%d\n", validInput);
    scanf("%s%c" , income, get);
    int length = strlen(get);
    if(get[0] == '\0'){
        printf("invalid!!");
    // for(int i = 0; i < length; i++){

    //     if(get){ 

    //         validInput = 0;

    //     } else{
            
    //     validInput = -1;
    //     break;
        
    // }
    // printf("%d\n", validInput);
    }

    return 0;
}
