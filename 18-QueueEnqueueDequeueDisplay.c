#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //pre-processor directive

int QUEUE[MAX],FRONT,REAR; // global declaration

//to display queue element
void display(int []); // Function declaration

//enqueue (insert) item into queue
void ENQUEUE(int [],int);

//deque (remove) item from queue
void DEQUEUE(int []);

int main()
{
    int ITEM = 0;
    int choice = 0;
    FRONT=-1;
    REAR=-1;

    while(1)
    {
        printf("1. Display\n");
        printf("2. Insert (ENQUEUE)\n");
        printf("3. Remove (DEQUEUE)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            display(QUEUE);
            break;
        case 2:
            printf("Enter item to be inserted: ");
            scanf("%d",&ITEM);
            ENQUEUE(QUEUE,ITEM);
            break;
        case 3:
            DEQUEUE(QUEUE);
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

void display(int queue[])
{
    int i=0;
    if(FRONT==-1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("FRONT --> ");
    for(int i=FRONT;i<=REAR;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("<-- REAR");
    printf("\n\n");
}

void ENQUEUE(int queue[],int item)
{
    if(REAR==MAX-1) //10-1=9
    {
        printf("OVERFLOW\n");
        return;
    }

    //for first element front is -1
    if(FRONT==-1)
    {
        FRONT=0;
        REAR=0;
    }
    else
        REAR++;
    queue[REAR] =item;
}

void DEQUEUE(int queue[])
{
    int deletedItem;
    if(FRONT==-1)
    {
        printf("QUEUE is EMPTY\n");
        return;
    }
    deletedItem = queue[FRONT];
    
    //If last element is being deleted we have to set both front and rear to -1
    if(FRONT==REAR)
    {
        FRONT=-1;
        REAR=-1;
    }
    else
        FRONT++;
    printf("%d deleted successfully\n",deletedItem);
    return;
}