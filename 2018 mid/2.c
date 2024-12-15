#include<stdio.h>

long factorial(int x){
    long fac = x;
    if (x > 0){// x!
        for (int i = x -1; i > 0; i--){
            fac *= i;
        }
    } else if (x == 0){
        fac = 1;
    }

    return fac;
}

long combinations(int n, int r){
    long ans;
    long f_n, f_r, f_nr;
    f_n = factorial(n);
    f_r = factorial(r);
    f_nr = factorial(n - r);
    ans = f_n/(f_r * f_nr);

    return ans;
}
long permutations(int n, int r){
    long ans;
    long f_n, f_nr;
    f_n = factorial(n);
    f_nr = factorial(n - r);

    ans = f_n/f_nr;

    return ans;
}

int main(){
    int n, r;
    long C_ans, P_ans;
    //getting inputs
    printf("Enter the values of n and r: ");
    scanf(" %d", &n);
    scanf(" %d", &r);

    // long fac = factorial(0);
    // printf("%ld", fac);
    if(n < 0 || r < 0){
        printf("Error: enter positive numbers");
    }
    else if (n < r){
        printf("Error: n has to be larger than r");
    }
    else {

        //processing
        P_ans = permutations(n, r);
        C_ans = combinations(n, r);

        //outputs
        printf("%dC%d = %ld\n", n, r, C_ans);
        printf("%dP%d = %ld\n", n, r, P_ans);

    }


    return 0;
}