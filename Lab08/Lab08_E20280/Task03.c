#include<stdio.h>

int main(){
    int rows;
    //getting num of rows
    if (scanf(" %d", &rows)){
        if (rows > 0){
            int matrix[rows][rows];
            for (int i = 0; i < rows; i++){ // making pascal triangle
                for (int e = i; e >= 0; e--){
                    if (i == e || e == 0){
                        matrix[i][e] = 1;
                    }
                    else {
                        matrix[i][e] = matrix[i - 1][e] + matrix[i - 1][e - 1];
                    }
                }
            }       
            for (int i = 0; i < rows; i++){ // printing pascal triangle
                for (int e = i; e >= 0; e--){
                    printf("%d ",matrix[i][e]);
                }
                printf("\n");
            }
        }
        else{
            printf("Please enter a positive integer.\n");
        }
    } else {
        printf("Invalid input format. Terminating the program.\n");
    }
    return 0;
}