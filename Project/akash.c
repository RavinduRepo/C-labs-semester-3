#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char **map;  // GLOBAL 2D CHARACTER ARRAY
// int g=0;
int map_H,map_W;
int **check; //Global 2D NUMBER ARRAY
// int check[50][50];
int _S1,_S2;
int _E1,_E2;

//declare functions
void string_to_2d_array(char *HW ,int map_H,int map_W);
int shortest_path(int g);
bool is_valid_move(char currentCell, char nextCell);

int main(){

    //input map height and width
    scanf(" %d %d ",&map_H,&map_W);
    scanf("%d %d ",&_S1,&_S2);
    scanf("%d %d  ",&_E1,&_E2);
    char HW[map_H*map_W+1];
    scanf("%s",HW);
    
    // NUMBER ARRAY
    check = (int **)malloc(map_H * sizeof(int *));   // AllOCATE memory for the array of pointers to rows
    for (int i = 0; i < map_H; i++) {                      // ALLOCATE memory for each row
        check[i] = (int *)malloc(map_W* sizeof(int));
    }

    //ASSING -1 FOR ALL ELEMENTS IN NUMBER ARRAY
    for(int i=0;i<map_H;i++){
        for(int j=0;j<map_W;j++){
            if (i == _E1 && j == _E2){
                check[i][j]= 0; //ASSIGN AS 0 FOR THE DESTINATION
            }
            else{
            check[i][j]=-1;
            }
        }
    }


    string_to_2d_array(HW,map_H,map_W);   //CALL MAKING CHARACTER ARRAY

    // for(int i=0;i<map_H;i++){
    //     for(int j=0;j<map_W;j++){
    //         printf("%c\t",check[i][j]);
    //         printf("%c\t",map[i][j]);
    //     }
    //     printf("\n");
    //     }
    
    int ans = shortest_path(0);
    if(ans == -1){
        printf("There is no possible path from %c to %c",map[_S1][_S2], map[_E1][_E2]);
    }else{
        printf("The minimum distance from %c to %c is %d",map[_S1][_S2],map[_E1][_E2],ans);
    }
    


    return 0;
    }

    //FUNCTION OF FINDING SHORTEST PATH
    int  shortest_path(int g){

        for(int i=0;i<map_H;i++){
            for(int j=0;j<map_W;j++){
                if(check[_S1][_S2] != -1 || g == map_H*map_W){
                    return check[_S1][_S2];
                }
                if(check[i][j]==g){
                        if((i+1>=0 && j>=0)  && (i+1<map_H && j< map_W) && (check[i+1][j]==-1) && is_valid_move(map[i][j],map[i+1][j])){ //MOVE DOWN
                            check[i+1][j]=g+1;

                        }if((i-1>=0 && j>=0)  &&  (i-1<map_H && j< map_W) && (check[i-1][j]==-1) && is_valid_move(map[i][j],map[i-1][j])){   //MOVE UP
                            check[i-1][j]=g+1;

                        }if((i>=0 && j+1>=0) &&  (i<map_H && j+1< map_W) && (check[i][j+1]==-1) && is_valid_move(map[i][j],map[i][j+1])){  //MOVE RIGHT
                            check[i][j+1]=g+1;

                        }if((i>=0 && j-1>=0)  && (i<map_H && j-1< map_W) && (check[i][j-1]==-1) &&  is_valid_move(map[i][j],map[i][j-1])){    //MOVE LEFT
                            check[i][j-1]=g+1;

                        }                      
                }
            }
        }
        return shortest_path(g+1);  
    }


   
    //FUNCTION OF MAKING  2 D ARRAY
    void string_to_2d_array(char *HW ,int map_H,int map_W){
         int i, j, k = 0;
         // Allocate memory
        map= (char **)malloc(map_H * sizeof(char *));//allocates memory for map_H rows of pointers.
        for(int i = 0; i < map_H; i++) {
            map[i] = (char *)malloc(map_W * sizeof(char));//allocates memory for map_W characters in each row.
        }

        for (i = 0; i < map_H; i++) {
            for (j = 0; j < map_W; j++) {
                map[i][j] = HW[k++];
            }
        }
    }
    //CHECK IT CAN BE MOVE TO NEXT POSITION
    bool is_valid_move(char current, char next){
    int Diff=next-current;
    return (Diff<=3 && Diff>=0) || (Diff>=-2 && Diff<0);
    }