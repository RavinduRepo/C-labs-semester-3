#include<stdio.h>
#include <stdlib.h>
#include <string.h>


// Initalizing variables
char **Map;
int mapH, mapW;
int StartRow, StartCol;
int EndRow, EndCol;
char *mapdetails;

// void printArray(char string[], int size);
void printArray(char **string, int sizeR, int sizeC);                       // Prints the given array
void makeArray();                                                           // Make map using the input array
int minDistance();                                                          //Search for min distence and prints
int isValidMove(int nextR, int nextC);                                      // Check if the move is in the map
int isTravlePossible(char C, char N);     // Check if possible to travel

int main(){

        // getting inputs
    scanf(" %d %d", &mapH, &mapW);//hight width inputs

    scanf(" %d %d", &StartRow, &StartCol);//startpoints

    scanf(" %d %d", &EndRow, &EndCol);//endpoints

    mapdetails = (char *)malloc((mapH * mapW) + 1);// create input string

    scanf(" %s", mapdetails);

        // Creating 2d array
    makeArray();

    // printArray(Map, mapH, mapW);//prints input array if need

    int steps = minDistance();
    if (steps == -1){
        printf("There is no possible path from %c to %c", Map[StartRow][StartCol], Map[EndRow][EndCol]);
    } else {
        printf("The minimum distance from %c to %c is %d", Map[StartRow][StartCol], Map[EndRow][EndCol], steps);
    }

    return 0;
}

void printArray(char **string, int sizeR, int sizeC){
    for (int r = 0; r < sizeR; r++){
        for (int c = 0; c < sizeC; c++){
            printf("%c ",string[r][c]);
        }
        printf("\n");
    }

}

void makeArray(){
        // Allocate memory
    Map = (char **)malloc(mapH * sizeof(char *));
    for(int i = 0; i < mapH; i++) {
        Map[i] = (char *)malloc(mapW * sizeof(char));
    }
    
    int index = 0;
    for (int r = 0; r < mapH; r++){
        for (int c = 0; c < mapW; c++){
            Map[r][c] = mapdetails[index];
            index++;
        }
    }
}

int minDistance(){

    // Make a Road 2D array
    int Road[mapH][mapW];
    for (int r = 0; r < mapH; r++){
        for (int c = 0; c < mapW; c++){
            Road[r][c] = -1;// set all other place -1
            if (r == EndRow && c == EndCol){
                Road[r][c] = 0;
            }
        }
    }

    //searching for best path
    char rValues[mapH * mapW];
    sprintf(rValues, "%d", EndRow);
    char cValues[mapH * mapW];
    sprintf(cValues, "%d", EndCol);

    for (int i = 0; mapH * mapW > i; i++){
        for (int indexC = 0, initialC = cValues[indexC] - '0'; cValues[indexC] != '\0'; indexC++){
            for (int indexR = 0, initialR = rValues[indexR] - '0'; rValues[indexR] != '\0'; indexR++){
                if (Road[initialR][initialC] == i){
                    // check above
                    if (isValidMove(initialR - 1, initialC) && isTravlePossible(Map[initialR][initialC], Map[initialR - 1][initialC]) && Road[initialR - 1][initialC] == -1){
                        Road[initialR - 1][initialC] = Road[initialR][initialC] + 1;
                    }

                    // check below
                    if (isValidMove(initialR + 1, initialC) && isTravlePossible(Map[initialR][initialC], Map[initialR + 1][initialC]) && Road[initialR + 1][initialC] == -1){
                        Road[initialR + 1][initialC] = Road[initialR][initialC] + 1;
                    }

                    // check left
                    if (isValidMove(initialR, initialC - 1) && isTravlePossible(Map[initialR][initialC], Map[initialR][initialC - 1]) && Road[initialR][initialC - 1] == -1){
                        Road[initialR][initialC - 1] = Road[initialR][initialC] + 1;
                    }
                    
                    // check right
                    if (isValidMove(initialR, initialC + 1) && isTravlePossible(Map[initialR][initialC], Map[initialR][initialC + 1]) && Road[initialR][initialC + 1] == -1){
                        Road[initialR][initialC + 1] = Road[initialR][initialC] + 1;
                    }
                }
                // printf("r: %s\tc: %s\n", rValues, cValues);
                char R[10], C[10];
                strcpy(rValues, "");
                strcpy(cValues, "");
                for (int r = 0; r < mapH; r++){
                    for (int c = 0; c < mapW; c++){
                        if (Road[r][c] == i + 1){
                            sprintf(R, "%d",r);
                            strcat(rValues, R);
                            sprintf(C, "%d",c);
                            strcat(cValues, C);           
                            // index++;
                        }
                    }
                }
            }
        }   
    }

    // // Prints the Road
    // printf("Road is:\n");
    // for (int r = 0; r < mapH; r++){
    //     for (int c = 0; c < mapW; c++){
    //         printf("%d\t",Road[r][c]);
    //     }
    //     printf("\n");
    // }

    return Road[StartRow][StartCol];
}

int isValidMove(int nextR, int nextC){
    return !(0 > nextR || nextR > mapH || 0 > nextC || nextC > mapW);
}

int isTravlePossible(char C, char N){
    // Check down(since walking back checks for only 2 stepsdown)   //Check up(since walking back checks 3 steps up)
    return !(C - N > 2             || N - C > 3);
}