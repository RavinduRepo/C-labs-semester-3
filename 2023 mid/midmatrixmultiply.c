#include<stdio.h>
int main(){
    int R1, C1;
    int R2, C2;
    
    scanf(" %d %d", &R1, &C1);
    scanf(" %d %d", &R2, &C2);

    if (C1 != R2){
        printf("Error: cannot multiply");
    }
    else {
        int M1[R1][C1];
        int M2[R2][C2];
        int ans[R1][C2];
        for (int r = 0; r < R1; r++){
            for (int c = 0; c < C1; c++){
                scanf(" %d", &M1[r][c]);
            }
        }
        for (int r = 0; r < R2; r++){
            for (int c = 0; c < C2; c++){
                scanf(" %d", &M2[r][c]);
            }
        }
        for (int r = 0; r < R1; r++){
            for (int c = 0; c < C2; c++){
                int sum = 0;
                for (int i = 0; i < C1; i++){
                    sum += M1[r][i] * M2[i][c];
                }
                ans[r][c] = sum;
            }
        }
        for (int r = 0; r < R1; r++){
            for (int c = 0; c < C2; c++){
                printf("%d ", ans[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}