#include<stdio.h>
#include<stdlib.h>

typedef struct _{
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
    struct _ *next;
}student_t;

student_t *addStudent(student_t *head)
{
    student_t *current;
    current=(student_t*)malloc(sizeof(student_t));
    current->next=head;
    printf("Enter the batch (17/18/19/20/21): ");
    scanf(" %d",&current->batch);
    printf("Enter the registration number: ");
    scanf(" %d",&current->regNo);
    printf("Enter the first name         : ");
    scanf(" %s",current->firstName);
    printf("Enter the last name          : ");
    scanf(" %s",current->lastName);
    printf("Enter the cumulative GPA     : ");
    scanf(" %f",&current->cGPA);
    printf("\n");
    head=current;
    return head;
}

void printStudent(student_t *head)
{
    int registrationNumber,batchNumber;
    printf("Enter the Registration Number: ");
    getchar();
    scanf("/%d/%d",&batchNumber,&registrationNumber);
    int studentFound=0;
    while(head!=NULL){
        if(head->batch==batchNumber && head->regNo==registrationNumber){
            printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",head->firstName,head->lastName,head->batch,head->regNo,head->cGPA);
            studentFound=1;
        }
        head=head->next;
    }
    if(!studentFound){
        printf("No student with the given Registration Number!\n");
        printf("\n");
    }
}

void printAllAtudents(student_t *head)
{
    while(head!=NULL){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",head->firstName,head->lastName,head->batch,head->regNo,head->cGPA);
        head=head->next;
    }
    
}


student_t *deleteStudent(student_t *head)
{
    int registrationNumber,batchNumber;
    printf("Enter the Registration Number: ");
    getchar();
    scanf("/%d/%d",&batchNumber,&registrationNumber);
    student_t *previous=NULL;
    student_t *current=head;
    while(current!=NULL){
        if(current->batch==batchNumber && current->regNo==registrationNumber){
            if(previous==NULL){
                head=current->next;
            }else{
                previous->next=current->next;
            }
            free(current);
            printf("Delete Successful!\n");
            printf("\n");
            return head;
        }
        previous=current;
        current=current->next;
    }
    printf("\n");
    return head;
}

int main()
{
    printf("--------------------------------------------\n");
    printf("A VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n");
    printf("--------------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Insert a Student Record\n");
    printf("2. Print a Student Record\n");
    printf("3. Print all Student Records\n");
    printf("4. Delete a Student Record\n");
    int option;
    student_t *head=NULL;
    while(1){
        printf("------------------\n");
        printf("ENTER OPTION [0-4]\n");
        printf("------------------\n");
        scanf("%d",&option);
        getchar();
        if(option==0){
            break;
        }else if(option==1){
            head=addStudent(head);
        }else if(option==2){
            printStudent(head);
            printf("\n");
        }else if(option==3){
            printAllAtudents(head);
            printf("\n");
        }else if(option==4){
            head=deleteStudent(head);
        }
    }
    return 0;
}