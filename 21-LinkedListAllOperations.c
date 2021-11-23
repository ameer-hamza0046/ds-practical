#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* HEAD = NULL;

int isEmpty()
{
    if(HEAD==NULL)
        return 1;
    return 0;
}

void insertAtBeg(int a)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = HEAD;
    HEAD = newnode;
}

void insertAtEnd(int a)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;

    if(isEmpty())
    {
        HEAD = newnode;
        return;
    }

    struct node* t = HEAD;

    while(t->next != NULL)
        t=t->next;
    
    t->next = newnode;   
}

// to insert a node at a specific index in the list
void insertAtLocation(int a,int loc)
{
    struct node* newnode;
    newnode = (struct node*) malloc (sizeof(struct node));
    newnode -> data = a;
    newnode -> next = NULL;

    if(loc == 0)
    {
        newnode -> next = HEAD;
        HEAD = newnode;
        return;
    }

    int curr_loc = 0;
    struct node* t = HEAD;
    while(t != NULL)
    {
        if(curr_loc == loc - 1)
            break;
        curr_loc++;
        t=t->next;
    }
    if(t==NULL)
    {
        printf("Invalid location\n");
        return;
    }
    newnode -> next = t -> next;
    t -> next = newnode;
}

//to insert after a specific node
void insertAfterNode(int value,int node_value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    struct node* t = HEAD;
    while(t!=NULL && t->data!=node_value)
    {
        t=t->next;
    }
    if(t==NULL)
    {
        printf("No node found with value %d\n",node_value);
        return;
    }
    newnode->next = t->next;
    t->next=newnode;
}

void deleteAtBeg()
{
    if(isEmpty())
    {
        printf("List is already empty!\n");
        return;
    }
    struct node* t = HEAD;
    HEAD = HEAD->next;
    free(t);
}

void deleteAtEnd()
{
    if(isEmpty())
    {
        printf("List is already empty!\n");
        return;
    }
    struct node* t = HEAD;
    if(HEAD->next == NULL)
    {
        HEAD = NULL;
        free(t);
        return;
    }
    while(t->next->next != NULL)
    {
        t=t->next;
    }
    struct node* p = t->next;
    t->next = NULL;
    free(p);
}

// to delete a node a given index
void deleteAtLocation(int loc)
{
    if(isEmpty())
    {
        printf("List is already empty!\n");
        return;
    }

    struct node* t = HEAD;
    if(loc==0)
    {
        HEAD = HEAD -> next;
        free(t);
        return;
    }

    int curr_loc = 0;
    while(t->next!=NULL)
    {
        if(curr_loc == loc-1)
            break;
        curr_loc++;
        t=t->next;
    }
    if(t->next==NULL)
    {
        printf("Invalid location\n");
        return;
    }
    struct node* p = t->next;
    t->next = p->next;
    free(p);
}

// to delete a node with a specific value
void deleteNodeOfValue(int node_value)
{
    if(isEmpty())
    {
        printf("List is already empty!\n");
        return;
    }
    struct node* t = HEAD;
    if(HEAD->data == node_value)
    {
        HEAD=HEAD->next;
        free(t);
        return;
    }
    while(t->next!=NULL)
    {
        if(t->next->data == node_value)
            break;
        t=t->next;
    }
    if(t->next==NULL)
    {
        printf("Node with value %d not found in the list\n",node_value);
        return;
    }
    struct node* p = t->next;
    t->next = p->next;
    free(p);
}

void printlist()
{
    if(isEmpty())
    {
        printf("List is empty!\n");
        return;
    }
    struct node* t = HEAD;
    while(t!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("NULL\n");
}

// FUNCTIONS ADDED LATER IN THE PROGRAM

int countElement(int key)
{
    int count = 0;
    struct node* t = HEAD;
    while(t!=NULL)
    {
        if(t->data == key)
            count++;
        t=t->next;
    }
    return count;
}

void add10()
{
    struct node* t = HEAD;
    while(t!=NULL)
    {
        t->data = t->data+10;
        t=t->next;
    }
}
////////////////////////////////////////


int menu()
{
    printf("1 . Insert at Beginning\n");
    printf("2 . Insert at End\n");
    printf("3 . Insert at Location\n");
    printf("4 . Insert after a specific node\n");
    printf("5 . Delete at Beginning\n");
    printf("6 . Delete at End\n");
    printf("7 . Delete at Location\n");
    printf("8 . Delete a specific node\n");
    printf("9 . Print List\n");
    printf("THE FOLLOWING FUNCTIONS ARE ADDED LATER!!\n");
    printf("10. Count the number of times an element has occured in the linked list\n");
    printf("11. Increase the elements of the list by 10\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    return choice;
}

int main()
{
    int value,location,node_value;
    while(1)
    {
        printf("Press any key to continue...");
        getch();
        system("cls");
        switch(menu())
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertAtBeg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&value);
                printf("Enter location: ");
                scanf("%d",&location);
                insertAtLocation(value,location);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d",&value);
                printf("Enter the value of node after which you want to insert: ");
                scanf("%d",&node_value);
                insertAfterNode(value,node_value);
                break;
            case 5:
                deleteAtBeg();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter location: ");
                scanf("%d",&location);
                deleteAtLocation(location);
                break;
            case 8:
                printf("Enter the value of the node you want to delete: ");
                scanf("%d",&node_value);
                deleteNodeOfValue(node_value);
                break;
            case 9:
                printlist();
                break;
            case 10:
                printf("Enter the element you want to count: ");
                scanf("%d",&value);
                printf("The number of times the element %d has occured in the list is %d\n",value,countElement(value));
                break;
            case 11:
                add10();
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid Input!!\n");
                break;
        }
    }
    return 0;
}
