#include<stdio.h>

void swap(long long *arr, int index); //swaps elements is index with the element in index + 1
void sort(long long *arr, int size); //bubble sort


int main(){
    int size;
    if (scanf(" %d", &size)){ //scans the size for the array
        fprintf(stderr, "size : %d\n", size);
        if (0 < size && size < 50){

            long long arr[size];//create array
            
            for (int i = 0; i < size; i++){ //getting inputs
                if (!scanf(" %lld", &arr[i])){
                    printf("Invalid input\n");
                    return 0;
                }
                fprintf(stderr, "%lld ", arr[i]);
            }

            // prints the given array
            printf("Given array: [");
            for (int i = 0; i < size; i++){//print arr
                printf("%lld", arr[i]);
                if (i != size - 1){
                    printf(", ");
                }
            }
            printf("]\n");

            sort(arr, size);// bubble sort

            // prints sorted array
            printf("Sorted array: [");
            for (int i = 0; i < size; i++){//print arr
                printf("%lld", arr[i]);
                if (i != size - 1){
                    printf(", ");
                }
            }
            printf("]\n");
        }
        else{
            printf("Invalid input\n");
        }
    }
    else{
        printf("Invalid input\n");
    }
    return 0;
}

void swap(long long *arr, int index){
        long long temp; 
        temp = arr[index]; // temperarily story value in index
        arr[index] = arr[index + 1]; // store value in index + 1 in index
        arr[index + 1] = temp;  // store value in index + 1 that was stored fom index
}

void sort(long long *arr, int size){
    int sorted = 0; // keep track on if no swaps happes, to end the swapping
    while (!sorted){
        sorted = 1;
        for (int i = 0; i < size - 1; i++){
            if (arr[i] > arr[i + 1]){
                swap(arr, i);
                sorted = 0;
            }
        }
    }
}