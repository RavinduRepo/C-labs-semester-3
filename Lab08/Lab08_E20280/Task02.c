#include<stdio.h>

int main(){
    int r, c;
    scanf (" %d %d", &r, &c); // gettting size inputs
    if (r <= 0 || c <= 0){
        printf("Error: Both rows and cols must be greater than 0\n");
        return 0;
    }
    long matrix[r][c]; // making matrix array

    for (int i = 0; i < r; i++){ // scanning matrix values
        for (int j = 0; j  < c; j++){
            scanf(" %ld", &matrix[i][j]);
        }
    }

    //print original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j  < c; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int isSame = 1;
    long transposeM[c][r];
    for (int i = 0; i < r; i++){ // transpose
        for (int j = 0; j  < c; j++){
            transposeM[j][i] = matrix[i][j];
        }
    }

    //print transpose matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < c; i++){
        for (int j = 0; j  < r; j++){
            printf("%ld ", transposeM[i][j]);
            if (transposeM[i][j] != matrix[i][j]){
                isSame = 0;
            }
        }
        printf("\n");
    }

    //print if same
    if (r == c && isSame){
        printf("Both matrices are the same\n");
    }
    else {
        printf("Matrices are different\n");
    }

    return 0;
}