#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node node;

node* newnode(int key)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = key;
    n->next = NULL;
    return n;
}

node* FRONT = NULL;
node* REAR = NULL;

void enqueue(int key)
{
    node* n = newnode(key);

    if(REAR==NULL)
    {
        REAR = n;
        FRONT = n;
        return;
    }

    REAR->next = n;
    REAR = n;
}

void dequeue()
{
    if(FRONT == NULL)
    {
        printf("Underflow\n");
        return;
    }
    if(FRONT == REAR)
    {
        node* n = FRONT;
        FRONT = NULL;
        REAR = NULL;
        free(n);
        return;
    }

    node* n = FRONT;
    FRONT = FRONT->next;
    free(n);
}

void display()
{
    if(FRONT==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    node* t = FRONT;

    printf("FRONT -> ");
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("<- REAR\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    enqueue(40);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}

