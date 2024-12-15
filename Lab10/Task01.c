#include<stdio.h>
#include<stdlib.h>
#define TRUE 1

typedef struct _{ //custom variable
    int batch;
    int regNo;
    char firstname[20];
    char lastname[20];
    float cGPA;
    struct _* next;
}student_t;

void printoptions(); // Print simple UI
void printStudent(student_t *current); // Prints the current student detaails
student_t *insertStudent(student_t *student); // Add new student
void printAstudent(student_t *student); // Prints the specific student's detals
void printAll(student_t *student); // prints details of all students
student_t *delStudent(student_t *student); // Delete specific student's details

int main(){
    student_t *student = NULL; // initial pointer variable as the head
    int option = 0; // default option 
    printoptions(); // Print simple UI
    while (TRUE){
        printf("\n------------------\n");
        printf("ENTER OPTION [0-4]\n");
        printf("------------------\n");
        scanf(" %d", &option); // scans for the option
        getchar(); // remove the newline character
        if(option == 0){ // Quit option
            return 0;
        }
        else if(option == 1){ // Insert new student
            student = insertStudent(student); // replace old head address from new one
        }
        else if(option == 2){ // Prints specific student's data
            printAstudent(student);
        }
        else if(option == 3){ // print all student records
            printAll(student);
        }
        else if(option == 4){
            student = delStudent(student); // replaces old head address from new head adress
        }
    }
    return 0;
}

student_t *delStudent(student_t *student){ // Delete specific student's details
    int batch, regNo;
    printf("Enter the Registration Number: ");
    getchar();
    scanf("/%d/%d", &batch, &regNo); // scans for batch number and regNo
    student_t *current = student; // temperoryly saves head address as current 
    student_t *prev = NULL; // to save previous point's address (after deleting have to connect next address in previous with next address of currrent)
    while (current != NULL){ // untill list ends 
        if (current->batch == batch && current->regNo == regNo){ // check if matches inputed data
            if (prev == NULL){ // if need to remove the head address student's data
                student = current->next; // replaces next adress as the new head
            }
            else {
                prev->next = current->next; // if need to remove middle point
            }
            free(current); // free the space from current (deleting point)
            printf("Delete Successful!\n");
            return student; // returning new head (usefull only when removing head)
        }
        prev = current; // saves previous "current" into prev for next loop
        current = current->next; // replaces current from next poin's address
    }    
    printf("No student with the given Registration Number!\n"); // prints error msg
    return student; 
}

void printAll(student_t *student){ // prints details of all students
    student_t *current = student;
    while (current != NULL){
        printStudent(current);
        current = current->next; 
    }
}

void printAstudent(student_t *student){ // Prints the specific student's detals
    int batch, regNo, found = 0;
    printf("Enter the Registration Number: ");
    getchar(); // remove char E from input
    scanf("/%d/%d", &batch, &regNo); // scans for batch number and regNo seperated with '/'
    student_t *current = student; //temparary coppy the head address
    while (current != NULL){
        if (current->batch == batch && current->regNo == regNo){ //check if match
            printStudent(current); // prints matched students data
            found = 1; // flag to indicate to not to print the Not found msg
        }
        current = current->next; // going to the next point
    }  
    if (!found){
        printf("No student with the given Registration Number!\n"); // prints the error msg
    }
}

student_t *insertStudent(student_t *student){ // Add new student
    student_t *current; // 
    current = (student_t*)malloc(sizeof(student_t));
    current->next = student; // store cuttent head address as next
   
    //insert a student record
    printf("Enter the batch (17/18/19/20/21): ");
    scanf(" %d", &current->batch);

    printf("Enter the registration number: ");
    scanf(" %d", &current->regNo);

    printf("Enter the first name         : ");
    scanf(" %s", current->firstname);

    printf("Enter the last name          : ");
    scanf(" %s", current->lastname);

    printf("Enter the cumulative GPA     : ");
    scanf(" %f", &current->cGPA);
    student = current; // replace old head address from new one
    return student; // return new head address
}

void printStudent(student_t *current){ // Prints the current student detaails
    printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", current->firstname, current->lastname, current->batch, current->regNo, current->cGPA);
}

void printoptions(){ // prints UI
        printf("--------------------------------------------\n");
        printf("A VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n");
        printf("--------------------------------------------\n");
        printf("0. Quit\n");
        printf("1. Insert a Student Record\n");
        printf("2. Print a Student Record\n");
        printf("3. Print all Student Records\n");
        printf("4. Delete a Student Record");
}




/*                          _QUESTIONS_

1) To calculate the memory allocated for the linked list with 5 data elements in student_t type,
we need to consider the size of each element in the linked list structure (student_t).

Size of each element = sizeof(int) + sizeof(int) + sizeof(char[20]) + sizeof(char[20]) + sizeof(float) + sizeof(struct _)

sizeof(int) = 4, 
sizeof(char[20]) = 20, 
sizeof(float) = 4, 
sizeof(struct _) = 4.

Size of each element = 4 + 4 + 20 + 20 + 4 + 4 = 56 bytes.

For 5 elements, the total memory allocated would be 5 * 56 = 280 bytes.


2) Memory allocation for the linked list happens when inserting a new student 
record in the insertStudent function. The malloc function is used to dynamically allocate 
memory for each new student node.Memory is freed in the delStudent function when a student 
record is deleted using the free function. The memory for the deleted node is released to the system.
(function have commented explainning how each line cintributes)



3) Deleting values in the linked list is implemented in the delStudent function. 
It iterates through the linked list, finds the node with the specified registration number, 
adjusts the pointers to bypass the node, frees the memory occupied by the node, 
and returns the new head of the list.
(function have commented explainning how each line cintributes)



4) While there is no explicit limitation on the number of student data entries, the program's use 
of dynamic memory allocation may be limited by the available system memory. The system may eventually 
run out of memory if a large number of student records are added.



5) Pros and cons of linked lists over arrays:

Pros:
Dynamic size:                           Linked lists can easily grow or shrink in size during runtime.
Efficient insertions and deletions:     Adding or removing elements in a linked list is more efficient than in an array.

Cons:
Random access:                          Linked lists have slower random access time(time takes to access a random value in the list) compared to arrays.
Extra memory:                           Each element in a linked list requires extra memory for the pointer.


6) For a system with exactly 1000 student records and no further additions or deletions, an array-based 
implementation might be more efficient. Arrays provide constant-time access to elements, and the fixed
size of 1000 records can be allocated in a single block of memory. This can result in better cache locality 
and potentially faster performance compared to a linked list in this specific scenario. However, if the size 
of the records or the need for dynamic resizing is a concern, a linked list might still be a reasonable choice.

*/