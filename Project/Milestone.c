#include<stdio.h>
#include <stdlib.h>
#include <string.h>


// Initalizing variables
char **Map;
int **Road;
int mapH, mapW;
int StartRow, StartCol;
int EndRow, EndCol;
char *mapdetails;

void makeArray();                                                           // Make map using the input array
int minDistance(int TR1, int TC1, int TR2, int TC2);                        //Search for min distence and prints
int isValidMove(int nextR, int nextC);                                      // Check if the move is in the map
int isTravlePossible(char C, char N);                                       // Check if possible to travel

int fibNo(int x);                                                           //calculates the xth fibonachi number

int main(){

    // getting inputs
    scanf(" %d %d", &mapH, &mapW);//hight width inputs

    scanf(" %d %d", &StartRow, &StartCol);//startpoints

    scanf(" %d %d", &EndRow, &EndCol);//endpoints

    mapdetails = (char *)malloc((mapH * mapW) + 1);// create input string

    scanf(" %s", mapdetails);// getting map details input

    int TR1, TC1, TR2, TC2;
    scanf("%d %d", &TR1, &TC1);
    scanf("%d %d", &TR2, &TC2);

    // creating 2d array
    makeArray();
    minDistance(TR1, TC1, TR2, TC2);// checking for the shortest distence path


    return 0;
}

void makeArray(){ 
    // allocate memory
    Map = (char **)malloc(mapH * sizeof(char *));
    Road = (int **)malloc(mapH * sizeof(int *));
    for(int i = 0; i < mapH; i++) {
        Map[i] = (char *)malloc(mapW * sizeof(char));
        Road[i] = (int *)malloc(mapW * sizeof(int)); 
    }
    // make map details
    int index = 0;
    for (int r = 0; r < mapH; r++){
        for (int c = 0; c < mapW; c++){
            Map[r][c] = mapdetails[index];
            index++;
        }
    }
    // make a Road 2D array
    for (int r = 0; r < mapH; r++){
        for (int c = 0; c < mapW; c++){
            Road[r][c] = -1;                    // set all other place -1
            if (r == EndRow && c == EndCol){
                Road[r][c] = 0;                 //set end to 0
            }
        }
    }
}

int fibNo(int x){
    int ans = 0;
    int  a, b;
    for (int i = 1; i <= x; i++){
        ans = (i == 1 || i == 2)? 1 : a + b;
        b = a;
        a = ans;
    }
    return ans;
}

int minDistance(int TR1, int TC1, int TR2, int TC2){

    //searching for best path
    int Q[mapH * mapW][2];  // making a Q
    Q[0][0] = EndRow;       //setting the starting place
    Q[0][1] = EndCol;
    int countTo = 1;        //end of the Q    
    int initialR, initialC; 

    for (int counted = 0; counted < countTo; counted++){        //runs untill all the posible cells are ended
        initialR = Q[counted][0];                               //setting checking cell cordinates
        initialC = Q[counted][1];
    
        // check above
        if (isValidMove(initialR - 1, initialC) && isTravlePossible(Map[initialR][initialC], Map[initialR - 1][initialC]) && Road[initialR - 1][initialC] == -1){
            Road[initialR - 1][initialC] = Road[initialR][initialC] + 1;
            Q[countTo][0] = initialR - 1;
            Q[countTo][1] = initialC;
            countTo++;
        }
        // check below
        if (isValidMove(initialR + 1, initialC) && isTravlePossible(Map[initialR][initialC], Map[initialR + 1][initialC]) && Road[initialR + 1][initialC] == -1){
            Road[initialR + 1][initialC] = Road[initialR][initialC] + 1;
            Q[countTo][0] = initialR + 1;
            Q[countTo][1] = initialC;
            countTo++;
        }
        // check left
        if (isValidMove(initialR, initialC - 1) && isTravlePossible(Map[initialR][initialC], Map[initialR][initialC - 1]) && Road[initialR][initialC - 1] == -1){
            Road[initialR][initialC - 1] = Road[initialR][initialC] + 1;
            Q[countTo][0] = initialR;
            Q[countTo][1] = initialC - 1;
            countTo++;
        }                
        // check right
        if (isValidMove(initialR, initialC + 1) && isTravlePossible(Map[initialR][initialC], Map[initialR][initialC + 1]) && Road[initialR][initialC + 1] == -1){
            Road[initialR][initialC + 1] = Road[initialR][initialC] + 1;
            Q[countTo][0] = initialR;
            Q[countTo][1] = initialC + 1;
            countTo++;
        }            
    }   
    int StoD = Road[StartRow][StartCol]; // returns the value in starting  location(started from the end and ending from the start)


    int StoT1 = Road[TR1][TC1] - Road[StartRow][StartCol];
    if (Road[TR1][TC1] != -1){
        if (StoT1 < 0){
            StoT1 *= -1;
        }
    } else{
        StoT1 = -1;
    }

    int StoT2 = Road[StartRow][StartCol] - Road[TR2][TC2];
    if (Road[TR2][TC2] != -1){
        if (StoT2 < 0){
            StoT2 *= -1;
        }
    } else{
        StoT2 = -1;
    }

    int T1toE = (Road[TR1][TC1] != -1 && Road[EndRow][EndCol] != -1)? Road[TR1][TC1] - Road[EndRow][EndCol] : -1;// portal 1 to end

    int T2toE = (Road[TR2][TC2] != -1 && Road[EndRow][EndCol] != -1)? Road[TR2][TC2] - Road[EndRow][EndCol] : -1;// portal 2 to end

    //priints the output
    printf("%d %d %d %d %d\n", StoD, StoT1, StoT2, T1toE, T2toE);

    return 0;

}

int isValidMove(int nextR, int nextC){ // checks if new cordinates are in the map
    return (nextR >= 0 && nextR < mapH && nextC >= 0 && nextC < mapW);
}

int isTravlePossible(char C, char N){
    // Check down(since walking back checks for only 2 stepsdown)   //Check up(since walking back checks 3 steps up)
    return (C - N <= 2 && N - C <= 3);
}
