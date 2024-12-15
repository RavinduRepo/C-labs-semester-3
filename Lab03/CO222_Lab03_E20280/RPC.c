#include<stdio.h>

//fuction for check validity
int checkValid(char char1, char char2) {
    char validInputs[] = {'R', 'P', 'S'};
    
    // Check if both inputs are valid inputs
    if ((char1 == validInputs[0] || char1 == validInputs[1] || char1 == validInputs[2]) && (char2 == validInputs[0] || char2 == validInputs[1] || char2 == validInputs[2])){
        return 1; // Return 1 if both inputs are valid
    } else {
        return 0; // Return 0 if either or both inputs are invalid
    }
}

void Round(int* playerAmarks, int* playerBmarks, int* error){
    char input1, input2;

    scanf(" %c %c", &input1, &input2);
    //adding marks to the winning player
    if(checkValid(input1, input2)){
        if((input1 == 'R' && input2 == 'S') || (input1 == 'P' && input2 == 'R') || (input1 == 'S' && input2 == 'P')){
            *playerAmarks += 1;
        } else if((input1 == 'S' && input2 == 'R') || (input1 == 'R' && input2 == 'P') || (input1 == 'P' && input2 == 'S')){
            *playerBmarks += 1;
        }
    } else{
        //prints the error massage
        // printf("Wrong input\n");
        *error = 1;//in the hackerrank the error massage gives after all rounds. this variable will act as a trigger for the error massage.
    }
}



int main(){
    int player1Marks = 0, player2Marks = 0, player3Marks = 0, error = 0;


    //getting inputs for rounds


    //Round 1; Player 1 vs 2
    Round(&player1Marks, &player2Marks, &error);
    // printf("player1: %d\nplayer2: %d\n" , player1Marks, player2Marks);

    //Round 2; Player 2 vs 3
    Round(&player2Marks, &player3Marks, &error);
    // printf("player2: %d\nplayer3: %d\n" , player2Marks, player3Marks);

    //Round 3; Player 1 vs 3
    Round(&player1Marks, &player3Marks, &error);
    // printf("player1: %d\nplayer3: %d\n" , player1Marks, player3Marks);

    //printing makrs of each player
    // printf("player1: %d\nplayer2: %d\nplayer3: %d\n" , player1Marks, player2Marks, player3Marks);
    
    
    //checking the winners

    //error massage print
    if(error){
        printf("Wrong input\n");
    }
    else if((player1Marks == player2Marks) && (player1Marks == player3Marks)){ //chechk for ties
        printf("Tie");
    }
    else if((player1Marks == player2Marks) && player1Marks != 0){
        printf("Player 1 and player 2 wins");
    }
    else if((player2Marks == player3Marks) && player2Marks != 0){
        printf("Player 2 and player 3 wins");
    }
    else if((player1Marks == player3Marks) && player1Marks != 0){
        printf("Player 1 and player 3 wins");
    }
    else if(player1Marks > player2Marks){
        if(player1Marks > player3Marks){
            printf("Player 1 wins");
        } else{
            printf("Player 3 wins");
        }
    }
    else if(player2Marks > player3Marks){
        printf("Player 2 wins");
    } else{
        printf("Player 3 wins");
    }
    return 0;
}