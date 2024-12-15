#include<stdio.h>

int main(){
    int elements;
    scanf(" %i", &elements);
    if (elements <= 0){
        printf("Invalid Array\n");
    }
    else {

        int list[elements];
        for (int i = 0; i < elements; i++){// scan list elements
            scanf (" %d",&list[i]);
        }
        int rotate;
        scanf(" %d", &rotate);//    get number of rotations

        printf("Original Array: "); //prints the list
        for (int i = 0; i < elements; i++){
            printf ("%d ",list[i]);
        }
        printf("\n");

        int actualR = rotate % elements;// calculates actual rotations
        if (actualR == 0){
            printf("No Rotation\n");
        }
        else if (actualR < 0){
            printf("Invalid Rotations\n");
        }
        else{
            printf("Actual Rotations: %d\n", actualR);

            int rotatedList[elements];
            for (int i = 0; i < elements; i++){ // saves rotated list
                rotatedList[(i + actualR) % elements] = list[i];
            }

            printf ("Rotated Array: ");
            for (int i = 0; i < elements; i++){ // priint rotated list
                printf ("%d ",rotatedList[i]);
            }
        }
     
    }


    return 0;
}