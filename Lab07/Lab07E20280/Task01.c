#include<stdio.h>

long fib(long num,long mem[]);

int main(){
    long num;
    long mem[100] ={0};

    scanf(" %ld", &num);

    printf("%ld", fib(num, mem));

    return 0;
}

long fib(long num, long mem[]){
    if (num == 1 || num == 0){
        return num;
    }
    if (mem[num] == 0){
        mem[num] = fib(num - 1, mem) + fib(num -2, mem);
    }
    return mem[num];
}