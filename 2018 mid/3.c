#include <stdio.h>
// #include <stdlib.h>

#define MEMORY_SIZE 10000

static char memory[MEMORY_SIZE];
static size_t next_index = 0;

void* my_malloc(size_t size) {
    if (next_index + size <= MEMORY_SIZE) {
        void* ptr = &memory[next_index];
        next_index += size;
        return ptr;
    } else {
        // Handle memory allocation failure
        return NULL;
    }
}


char* int2bin(int a) {
    char* binary = my_malloc(33);  // we can use maloc but here I have made maloc by myself
    binary[32] = '\0';
    unsigned int mask = 1 << 31;
    for(int i = 0; i < 32; i++) {
        binary[i] = (a & mask) ? '1' : '0';
        mask >>= 1;
    }
    return binary;
}

int main(){
    int number;
    printf("Enter an integer to be converted to binary: ");
    if (!scanf("%d", &number)){
        printf("Error: You should enter an integer\n");
        return -1;
    }
    char* binary = int2bin(number);
    printf("The binary value of number %d is %s.\n", number, binary);
    free(binary);
    return 0;
}
