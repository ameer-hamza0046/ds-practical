#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //pre-processor directive

int STACK[MAX],TOP; // global declaration

//to display stack element
void display(int []); // Function declaration

//push (insert) item into stack
void PUSH(int [],int);

//pop (remove) item from stack
void POP(int []);

int main()
{
    int ITEM = 0;
    int choice = 0;
    TOP=-1;

    while(1)
    {
        printf("1. Display\n");
        printf("2. Insert (PUSH)\n");
        printf("3. Remove (POP)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display(STACK);
            break;
        case 2:
            printf("Enter item to be inserted: ");
            scanf("%d",&ITEM);
            PUSH(STACK,ITEM);
            break;
        case 3:
            POP(STACK);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}

void display(int stack[])
{
    int i=0;
    if(TOP==-1)
    {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("%d  <-- TOP",stack[TOP]);
    for(int i=TOP-1;i>=0;i--)
    {
        printf("\n%d",stack[i]);
    }
    printf("\n\n");
}

void PUSH(int stack[],int item)
{
    if(TOP==MAX-1) //10-1=9
    {
        printf("\nSTACK IS FULL, CAN'T ADD ITEM\n");
        return;
    }
    TOP++;
    stack[TOP] =item;
}

void POP(int stack[])
{
    int deletedItem;
    if(TOP==-1)
    {
        printf("STACK is EMPTY\n");
        return;
    }
    deletedItem = stack[TOP];
    TOP--;
    printf("%d deleted successfully\n",deletedItem);
    return;
}