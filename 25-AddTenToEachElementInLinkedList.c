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

void add10(node* head)
{
    node* t = head;
    while(t!=NULL)
    {
        t->data = t->data+10;
        t=t->next;
    }
}

int main()
{
    node* head = newnode(10);
    head->next = newnode(20);
    head->next->next = newnode(30);
    head->next->next->next = newnode(10);

    printf("original linked list is\n");
    printlist(head);

    add10(head);

    printf("linked list after modification\n");
    printlist(head);
    
    return 0;
}