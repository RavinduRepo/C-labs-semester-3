#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializing variables
char **Map;
int **Road;
int mapH, mapW;
int StartRow, StartCol;
int EndRow, EndCol;
char *mapdetails;

void makeArray();
int minDistance();
int isValidMove(int nextR, int nextC);
int isTravelPossible(char C, char N);

int main() {
    // Getting inputs
    scanf("%d %d", &mapH, &mapW); // Height and width inputs

    scanf("%d %d", &StartRow, &StartCol); // Start points

    scanf("%d %d", &EndRow, &EndCol); // End points

    mapdetails = (char *)malloc((mapH * mapW) + 1); // Create input string

    scanf("%s", mapdetails);

    // Creating 2D array
    makeArray();

    int steps = minDistance();
    if (steps == -1) {
        printf("There is no possible path from %c to %c", Map[StartRow][StartCol], Map[EndRow][EndCol]);
    } else {
        printf("The minimum distance from %c to %c is %d", Map[StartRow][StartCol], Map[EndRow][EndCol], steps);
    }

    // Free allocated memory
    for (int i = 0; i < mapH; i++) {
        free(Map[i]);
        free(Road[i]);
    }
    free(Map);
    free(Road);
    free(mapdetails);

    return 0;
}

void makeArray() {
    // Allocate memory for Map and Road
    Map = (char **)malloc(mapH * sizeof(char *));
    Road = (int **)malloc(mapH * sizeof(int *));
    for (int i = 0; i < mapH; i++) {
        Map[i] = (char *)malloc(mapW * sizeof(char));
        Road[i] = (int *)malloc(mapW * sizeof(int));
    }

    // Initialize Map from mapdetails
    int index = 0;
    for (int r = 0; r < mapH; r++) {
        for (int c = 0; c < mapW; c++) {
            Map[r][c] = mapdetails[index];
            index++;
        }
    }

    // Initialize Road array to -1 for all elements
    for (int r = 0; r < mapH; r++) {
        for (int c = 0; c < mapW; c++) {
            Road[r][c] = -1;
        }
    }

    // Set starting and ending positions to 0
    Road[StartRow][StartCol] = 0;
    Road[EndRow][EndCol] = 0;
}

int minDistance() {
    // Make a Road 2D array
    for (int r = 0; r < mapH; r++) {
        for (int c = 0; c < mapW; c++) {
            Road[r][c] = -1;
            if (r == EndRow && c == EndCol) {
                Road[r][c] = 0;
            }
        }
    }

    // Search for best path
    char rValues[mapH * mapW];
    sprintf(rValues, "%d", EndRow);
    char cValues[mapH * mapW];
    sprintf(cValues, "%d", EndCol);

    for (int i = 0; mapH * mapW > i; i++) {
        for (int indexR = 0, initialR = rValues[indexR] - '0'; rValues[indexR] != '\0'; indexR++) {
            for (int indexC = 0, initialC = cValues[indexC] - '0'; cValues[indexC] != '\0'; indexC++) {
                if (Road[initialR][initialC] == i) {
                    // Check above
                    if (isValidMove(initialR - 1, initialC) && isTravelPossible(Map[initialR][initialC], Map[initialR - 1][initialC]) && Road[initialR - 1][initialC] == -1) {
                        Road[initialR - 1][initialC] = i + 1;
                    }

                    // Check below
                    if (isValidMove(initialR + 1, initialC) && isTravelPossible(Map[initialR][initialC], Map[initialR + 1][initialC]) && Road[initialR + 1][initialC] == -1) {
                        Road[initialR + 1][initialC] = i + 1;
                    }

                    // Check left
                    if (isValidMove(initialR, initialC - 1) && isTravelPossible(Map[initialR][initialC], Map[initialR][initialC - 1]) && Road[initialR][initialC - 1] == -1) {
                        Road[initialR][initialC - 1] = i + 1;
                    }
                    
                    // Check right
                    if (isValidMove(initialR, initialC + 1) && isTravelPossible(Map[initialR][initialC], Map[initialR][initialC + 1]) && Road[initialR][initialC + 1] == -1) {
                        Road[initialR][initialC + 1] = i + 1;
                    }
                }
            }
        }
        char R[10], C[10];
        strcpy(rValues, "");
        strcpy(cValues, "");
        for (int r = 0; r < mapH; r++) {
            for (int c = 0; c < mapW; c++) {
                if (Road[r][c] == i + 1) {
                    sprintf(R, "%d", r);
                    strcat(rValues, R);
                    sprintf(C, "%d", c);
                    strcat(cValues, C);           
                }
            }
        }
    }

    return Road[StartRow][StartCol];
}

int isValidMove(int nextR, int nextC) {
    return !(nextR < 0 || nextR >= mapH || nextC < 0 || nextC >= mapW);
}

int isTravelPossible(char C, char N) {
    return !(C - N > 2 || N - C > 3);
}