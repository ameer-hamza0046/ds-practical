#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node node;

node* TOP = NULL;

node* newnode(int key)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = key;
    n->next = NULL;
    return n;
}

void push(int key)
{
    node* n = newnode(key);

    n->next = TOP;
    TOP = n;
}

void pop()
{
    if(TOP==NULL)
    {
        printf("Underflow\n");
        return;
    }
    node* n = TOP;
    TOP = TOP->next;
    free(n);
}

void display()
{
    if(TOP==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    node* t = TOP;
    printf("TOP-> ");

    while(t!=NULL)
    {
        printf("%d ",t->data);
        t =t->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
