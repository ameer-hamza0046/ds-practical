#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *newNode(int key)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = key;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

node *head = NULL;
node *tail = NULL;

void insertAtBegin(int key)
{
    node *n = newNode(key);

    if (head == NULL)
    {
        head = tail = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtEnd(int key)
{
    node *n = newNode(key);

    if (head == NULL)
    {
        head = tail = n;
        return;
    }

    n->prev = tail;
    tail->next = n;
    tail = n;
}
void insertAtLocation(int key, int loc)
{
    if (loc == 0)
    {
        insertAtBegin(key);
        return;
    }

    node *t = head;
    int i = 0;

    while (t != NULL)
    {
        if (i == loc)
            break;
        t = t->next;
        i++;
    }

    if (loc != i || t == NULL)
    {
        printf("Invalid location\n");
        return;
    }

    if (t == tail)
    {
        insertAtEnd(key);
        return;
    }
    node *n = newNode(key);
    n->next = t;
    n->prev = t->prev;
    n->prev->next = n;
    n->next->prev = n;
}

void deleteAtBegin()
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    if (head == tail)
    {
        node *t = head;
        head = tail = NULL;
        free(t);
        return;
    }

    node *t = head;
    head = head->next;
    head->prev = NULL;
    free(t);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    if (head == tail)
    {
        node *t = head;
        head = tail = NULL;
        free(t);
        return;
    }

    node *t = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(t);
    return;
}

void deleteAtLocation(int loc)
{
    if (loc == 0)
    {
        deleteAtBegin();
        return;
    }

    node *t = head;
    int i = 0;

    while (t != NULL)
    {
        if (i == loc)
            break;
        t = t->next;
        i++;
    }

    if (loc != i || t == NULL)
    {
        printf("Invalid location\n");
        return;
    }

    if (t == tail)
    {
        deleteAtEnd();
        return;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void printList()
{
    node *t = head;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int menu()
{
    printf("1 . Insert at Beginning\n");
    printf("2 . Insert at End\n");
    printf("3 . Insert at Location\n");
    printf("4 . Delete at Beginning\n");
    printf("5 . Delete at End\n");
    printf("6 . Delete at Location\n");
    printf("7 . Print List\n");
    printf("8 . Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int key, loc;
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &key);
            insertAtBegin(key);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &key);
            insertAtEnd(key);
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d", &key);
            printf("Enter the location: ");
            scanf("%d", &loc);
            insertAtLocation(key, loc);
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter the location: ");
            scanf("%d", &loc);
            deleteAtLocation(loc);
            break;
        case 7:
            printList();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Press any key to continue...");
        getch();
    }
    return 0;
}