
#include<stdio.h>

 int factorial ( int n ){
    int fac = n;
    if (n == 0){
        fac = 1;
        }
    if (n < 0){
        return ;
    }
    
    for (int i = n - 1; i > 0; i--){
        fac *= i;
    }
    
    return fac;
}


int main(){
    int num;

    // printf("Enter a number to calculate its factorial: ");
    scanf(" %d", &num);
    printf("%d\n",num);

    int fac = factorial(num);
    if (fac != 0){
        printf("Factorial of %d is %d\n", num, fac);
    }
    else {
        printf("Invalid input\n");
    }
    



    return 0;
}