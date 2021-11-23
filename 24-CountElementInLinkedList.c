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
    node* n = (node*) malloc(sizeof(node));
    n->data = key;
    n->next = NULL;
    return n;
}

int countElement(node* head, int key)
{
    int count = 0;
    node* t = head;
    while(t!=NULL)
    {
        if(t->data == key)
            count++;
        t=t->next;
    }
    return count;
}


void printlist(node* head)
{
    node* t = head;
    while(t)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main()
{
    node* head = newnode(10);
    head->next = newnode(20);
    head->next->next = newnode(30);
    head->next->next->next = newnode(10);
    printf("Given linked list is: ");
    printlist(head);
    int key = 10;
    int count = countElement(head,key);
    printf("Count of %d is %d\n",key,count);
    return 0;
}