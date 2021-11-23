#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //pre-processor directive

int CQUEUE[MAX], FRONT, REAR; // global declaration

//to display queue element
void display(int[]); // Function declaration

//enqueue (insert) item into queue
void ENQUEUE(int[], int);

//DEQUEUE (remove) item from queue
void DEQUEUE(int[]);

int main()
{
    int ITEM = 0;
    int choice = 0;
    FRONT = -1;
    REAR = -1;

    while (1)
    {
        printf("1. Display\n");
        printf("2. Insert (ENQUEUE)\n");
        printf("3. Remove (DEQUEUE)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(CQUEUE);
            break;
        case 2:
            printf("Enter item to be inserted: ");
            scanf("%d", &ITEM);
            ENQUEUE(CQUEUE, ITEM);
            break;
        case 3:
            DEQUEUE(CQUEUE);
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

void display(int cqueue[])
{
    if (FRONT == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("FRONT --> ");
    int i;
    if (FRONT <= REAR)
    {
        i = FRONT;
        while (i <= REAR)
        {
            printf("%d ", cqueue[i]);
            i++;
        }
    }

    else
    {
        i = FRONT;
        while (i <= MAX - 1)
        {
            printf("%d ", cqueue[i]);
            i++;
        }
        i = 0;
        while (i <= REAR)
        {
            printf("%d ", cqueue[i]);
            i++;
        }
    }
    printf("<-- REAR");
    printf("\n\n");
}

void ENQUEUE(int cqueue[], int item)
{
    if ((REAR == (MAX - 1) && FRONT == 0) || (FRONT == REAR + 1))
    {
        printf("OVERFLOW\n");
        return;
    }

    //for first element front is -1
    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else if (REAR == MAX - 1) //Rear at last index
        REAR = 0;
    else
        REAR++;
    cqueue[REAR] = item;
}

void DEQUEUE(int cqueue[])
{
    int deletedItem;
    if (FRONT == -1)
    {
        printf("QUEUE is EMPTY\n");
        return;
    }
    deletedItem = cqueue[FRONT];

    //If last element is being deleted we have to set both front and rear to -1
    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else if (FRONT == MAX - 1)
        FRONT = 0;
    else
        FRONT++;
    printf("%d deleted successfully\n", deletedItem);
    return;
}