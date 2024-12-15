#include <stdio.h>

/*
C program to rotate the items right in an array
 */

int num_array[100] = {0};
int shifted_num_array[100] = {0};
int size;

void rotation_func(); //Function to rotate the array to the counted amount

int main(){
    
    int rotation;
    
    scanf("%i",&size);
    if (size <= 0){
        printf("Invalid Array");
        return 0;
    }
    
    
    for (int i= 0 ; i < size ; i++){
        scanf("%d", &num_array[i]);
    }
    
    scanf("%d",&rotation);
    
    printf("Original Array: ");
    for (int i=0 ; i < size ; i++){
        printf("%d ", num_array[i]);
    }
    printf("\n");
    
    if (rotation < 0){
        printf("Invalid Rotations\n");
        return 0;
    }
    
    if (rotation % size == 0) {
        printf("No Rotation\n");
        return 0;
        
    }
    
    int rounds = 0;
    while (rounds < rotation){
        rotation_func();
        for (int i = 0 ; i < size ; i++){
            num_array[i] = shifted_num_array[i];
        }
        rounds = rounds + 1;
    }
    
    
    if (rotation > size) {
        printf("Actual Rotations: %d\n", rotation % size);
    }
    if (rotation < size){
        printf("Actual Rotations: %d\n", rotation);
    }
    
    
    printf("Rotated Array: ");
    for (int i=0 ; i < size ; i++){
        printf("%d ", num_array[i]);
    }
    
    return 0;
}

void rotation_func(){
    for (int i = 1 ; i < size-1 ; i++){
        shifted_num_array[i] = num_array[i-1];
    }
    shifted_num_array[0] = num_array[size-1];
    shifted_num_array[size-1] = num_array[size-2];
}