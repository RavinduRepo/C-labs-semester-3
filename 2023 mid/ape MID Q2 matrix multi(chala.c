#include <stdio.h>
int main(){
    int r1,c1,r2,c2,r3,c3;
    scanf("%d %d",&r1,&c1);
    scanf("%d %d",&r2,&c2);
    r3=r1;
    c3=c2;
    int arr1[r1][c1];
    int arr2[r2][c2];
    int arr3[r3][c3];
    for(int a=0;a<r1;a++){
        for(int b=0;b<c1;b++){
            scanf("%d",&arr1[a][b]);
        }

    }
    for(int a1=0;a1<r2;a1++){
        for(int b1=0;b1<c2;b1++){
            scanf("%d",&arr2[a1][b1]);
        }

    }
    int hm=0;
    for(int p=0;p<r1;p++){

    for(int w=0;w<c2;w++){
        int y1=0;
        for(int q=0;q<c1;q++){
            y1=y1+arr1[p][q]*arr2[q][w];
        }printf("%d ",y1);}
        printf("\n");



    }

    return 0;
}
