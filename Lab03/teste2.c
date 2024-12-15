#include <stdio.h>

int isValidInput(char char1, char char2) {
    char validInputs[] = {'R', 'P', 'S'};
    
    // Check if both characters are valid inputs
    if ((char1 == validInputs[0] || char1 == validInputs[1] || char1 == validInputs[2]) &&
        (char2 == validInputs[0] || char2 == validInputs[1] || char2 == validInputs[2])) {
        return 1; // Return 1 if both characters are valid
    } else {
        return 0; // Return 0 if either or both characters are invalid
    }
}

int main() {
    char input1, input2;

    // Get inputs from the user
    printf("Enter two characters separated by a space ('R', 'P', or 'S'): ");
    scanf(" %c %c", &input1, &input2);

    // Check the validity using the function
    if (isValidInput(input1, input2)) {
        printf("Both inputs are valid.\n");
    } else {
        printf("Invalid input(s).\n");
    }

    return 0;
}
