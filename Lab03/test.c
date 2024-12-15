#include <stdio.h>

int isValidInput(char char1, char char2) {
    char validInputs[] = {'R', 'P', 'S'};
    
    // Check if either char1 or char2 is a valid input
    for (int i = 0; i < sizeof(validInputs) / sizeof(validInputs[0]); i++) {
        if (char1 == validInputs[i] || char2 == validInputs[i]) {
            printf("invalid");
        } else{
            return 0;
        }
    }

    return 1; // Return 1 if either char1 or char2 is valid
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
