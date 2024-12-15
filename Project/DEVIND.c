#include <stdio.h>
#include <stdlib.h>

//initializing the global var
char **map;
int H,W,startrow,startcol,endrow,endcol;
char *string;
int **numberArray;//number array for path finding

//func prototype
void MakeMap();
void PrintMap();
int IsTravelAble(int nowrow, int nowcol, int nextrow,int nextcol );
int Cellcheck(int row, int col);
int shortest(int value);

int main(){
    scanf(" %d %d",&H,&W);
    scanf(" %d %d",&startrow,&startcol);
    scanf(" %d %d",&endrow,&endcol);
    //intializing string array
    string = (char *)malloc(H*W+1);
    scanf("%s",string);

    map = (char **)malloc(H*sizeof(char *));
    numberArray =(int **)malloc(H*sizeof(int *));
    for(int i=0; i<H;i++){
        map[i]=(char *)malloc(W*sizeof(char));
        numberArray[i]=(int *)malloc(W*sizeof(int));
    }
    MakeMap();

    numberArray[startrow][startcol]=1;

    PrintMap();

    printf("returned steps %d\n",shortest(1));
    //print num array
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%d\t",numberArray[i][j]);
        }
        printf("\n");
    }  
    return 0;
}

void MakeMap(){
    int index=0;
    for(int i=0; i<H;i++){
        for(int j=0;j<W;j++){
            map[i][j]=string[index];
            numberArray[i][j]=0;
            index+=1;
        }
    }
}

void PrintMap(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}

int IsTravelAble(int nowrow, int nowcol, int nextrow,int nextcol ){
    if(map[nextrow][nextcol]-map[nowrow][nowcol]<=2 && map[nowrow][nowcol]-map[nextrow][nextcol]<=3){
        return 1;
    }
    else{
        return 0;
    }
}

int Cellcheck(int row, int col){
    if((row>=0 && row < H)&&(col>=0 && col < W )){
        return 1;
    }
    else{
        return 0;
    }
}

int shortest(int value){
    //int row[H*W];
    //int col[H*W];
    //int count=0;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(numberArray[endrow][endcol] !=0 || value == H*W){
                return numberArray[endrow][endcol] - 1;
            }
            //getting the right cell
            if(numberArray[i][j]==value){            
                //move right
                if(Cellcheck(i,j+1)&&IsTravelAble(i,j,i,j+1)&&numberArray[i][j+1]==0){
                    numberArray[i][j+1]=value+1;
                    printf("checking right\n");
                }
                //move left
                if(Cellcheck(i,j-1)&&IsTravelAble(i,j,i,j-1)&&numberArray[i][j-1]==0){
                    numberArray[i][j-1]=value+1;
                    printf("checking left\n");
                }
                //move down
                if(Cellcheck(i+1,j)&&IsTravelAble(i,j,i+1,j)&&numberArray[i+1][j]==0){
                    numberArray[i+1][j]=value+1;
                    printf("checking down r:%d\tc:%d\n",i,j);
                    if(IsTravelAble(i,j,i+1,j)){
                        printf("POSSIBLE\n");
                    }
                        //print num array
                    for(int i=0;i<H;i++){
                        for(int j=0;j<W;j++){
                            printf("%d\t",numberArray[i][j]);
                        }
                        printf("\n");
                    }  
                }
                //move up
                if(Cellcheck(i-1,j)&&IsTravelAble(i,j,i-1,j)&&numberArray[i-1][j]==0){
                    numberArray[i-1][j]=value+1;
                    printf("checking up\n");
                }
                printf("%d\n\n",value);                
            }
        }
    }
    return shortest(value+1);
}

int *insertque(int arr[],int value,int count){
     arr[count]=value;
     return arr;
}
