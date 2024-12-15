#include<stdio.h>

int binarySearch(int arr[], int low, int high, int key);


int main(){
    int num;
    // printf("Enter the number of elements: ");
    scanf(" %d", &num);
    int arr[num];
    // printf("Enter the elements in sorted order:\n");
    int key;
    // printf("Enter the element to search: ");
    scanf(" %d", &key); 
    for (int i = 0; i < num; i++){
        scanf(" %d", &arr[i]);
    }
    
 

    int index = binarySearch(arr, 0, num - 1, key);
    if (index != -1){
        printf("Element %d found at index %d", key, index);
    } else {
        printf("Element %d not found in the array", key);
    }

    return 0;
}

int binarySearch(int arr[], int low, int high, int key){
    if (low <= high){
        int middle = (low + high) / 2;
        if (arr[middle] == key){
            return middle;    //base 
        }
        else if (arr[middle] > key){
            return binarySearch(arr, low, middle - 1, key);
        }
        else {
            return binarySearch(arr, middle + 1, high, key);
        }
    }
    else {
        return -1;
    }
}

