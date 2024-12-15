#include <stdio.h>
#include <stdlib.h>
char **myarray;
int **pathArray;
int **testArray;
int row,column,index =0,sr=0,sc=0,er,ec,rounds,up=0,down=0,left=0,right=0;
char str[500];
void makeMap(int row, int column){
    int index =0;
    myarray = (char**)malloc(row*sizeof(char*));
    for(int i =0; i<row; ++i){
        myarray[i] = (char*)malloc(column*sizeof(char));

    }
    //char str[]="ABCCDGLCKEZZBLFXYCMGDVEGH";
    for(int i=0; i<row; ++i){
        for(int j=0; j<column;++j){
                myarray[i][j] = str[index];
                index++;
        }
    }
}


int validmove(int nextR, int nextC){
    if ( nextR <0 || nextR>= row || nextC<0|| nextC >=column){                  //////CHANGE!!
        return 0;
    }else{
        return 1;
    }
}



int isPossible(int R, int C, int nextR, int nextC){
    if (myarray[R][C] - myarray[nextR][nextC] > 2 || myarray[nextR][nextC] - myarray[R][C] > 3){ //i changed this
         printf("impossible Move \n");
        return 0;
    } else {
         printf("possible Move\n");
        return 1;
    }

}



void initializePathArray(int sr, int sc,int row, int column){
    pathArray = (int**)malloc(row*sizeof(int*));
    testArray = (int**)malloc(row*sizeof(int*));
    for(int i =0; i<row; ++i){
        pathArray[i] = (int*)malloc(column*sizeof(int));
        testArray[i] = (int*)malloc(column*sizeof(int));

    }
    for(int i=0; i<row; ++i){
        for(int j=0; j<column;++j){
                pathArray[i][j] = -1;

                if(i == sr && j == sc){
                pathArray[i][j] = 0;
            }//printf("%d",pathArray[i][j]);
        }
    }
}



int isPath(int n){
    int  above=0,below=0,left=0,right =0;
    for (int r = 0; r<row; ++r){
        for (int c = 0; c<column; ++c){
            //printf("r c n pA %d %d %d %d\n",r,c,n,pathArray[r][c]);
            if (pathArray[er][ec]!= -1){
                    printf("break\n");
                return pathArray[er][ec];
            }else if( pathArray[r][c]== n ){
                printf("entered %d\n",n);
                //above
                if (pathArray[r][c]== n  && validmove(r-1,c) && isPossible(r,c,r-1,c)&&pathArray[r-1][c]==-1){
                    pathArray[r-1][c]= pathArray[r][c]+1;
                    printf("a; %d %c\n",pathArray[r-1][c],myarray[r][c]);
                    ++above;
                }
                //below
                if (pathArray[r][c]== n  && validmove(r+1,c) && isPossible(r,c,r+1,c)&&pathArray[r+1][c]==-1){
                    pathArray[r+1][c]= pathArray[r][c]+1;
                    printf("b; %d %c\n",pathArray[r+1][c],myarray[r][c]);
                    ++below;
                }
                //left
                if (pathArray[r][c]== n && validmove(r,c-1) && isPossible(r,c,r,c-1)&&pathArray[r][c-1]==-1 ){
                    pathArray[r][c-1]= pathArray[r][c]+1;
                    printf("l; %d %c\n",pathArray[r][c-1],myarray[r][c]);
                    ++left;
                }
                //right
                if (pathArray[r][c]== n && validmove(r,c+1) && isPossible(r,c,r,c+1)&&pathArray[r][c+1]==-1 ){
                    pathArray[r][c+1]= pathArray[r][c]+1;
                    printf("r; %d %c\n",pathArray[r][c+1],myarray[r][c]);
                    ++right;
                }

            }



        }
    }


    for(int i=0; i<row; ++i){
        for(int j=0; j<column;++j){
            printf("%d ",pathArray[i][j]);
        }printf("\n");
    }

    if(above+below+left+right ==0){
        return 0;
    }

    return isPath(n+1);

}
int main(){

    //char str[]="ABCCDGLCKEZZBLFXYCMGDVEGH";
    // printf("Enter rows and columns\n");
    scanf("%d %d",&row,&column);


    // printf("enter start\n");
    scanf("%d %d",&sr,&sc);


    // printf("enter end\n");
    scanf("%d %d",&er,&ec);


    // printf("enter string\n");
    scanf("%s",str);


    // printf("\n\n");
    // printf("%d %d, %d %d, %d %d",row,column,sr,sc,er,ec);
    // printf("\n\n");

    makeMap(row,column);

    for(int i=0; i<row; ++i){
        for(int j=0; j<column;++j){
            printf("%c\t",myarray[i][j]);
        }printf("\n");
    }
    printf("\n");

    initializePathArray(sr,sc,row,column);
    int path = isPath(0);
     if(path){
    printf("okey %d\n", path);
     }else{
     printf("no\n");
     }





    for(int i=0; i<row; ++i){
        for(int j=0; j<column;++j){
            printf("%d ",pathArray[i][j]);
        }printf("\n");
    }

}

