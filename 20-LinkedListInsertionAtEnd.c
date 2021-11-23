#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *HEAD = NULL;

void insertAtEnd(int a)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = a;
    new_node->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = new_node;
        return;
    }

    node *t = HEAD;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = new_node;
}

void printlist()
{
    node *t = HEAD;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main()
{
    printf("Enter -1 to end\n");
    while (1)
    {
        int k;
        printf("Enter value: ");
        scanf("%d", &k);
        if (k == -1)
            break;
        insertAtEnd(k);
    }
    printlist();
    return 0;
}