#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* newNode(int key)
{
    node* n = (node* )malloc(sizeof(node));
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

/*

stack implementation

stack[++top] = data; is equivalent to:
top = top + 1;
stack[top] = data;
i.e. push operation
--
data = stack[top--]; is equivalent to:
data = stack[top];
top = top-1;
i.e. pop operation

*/

void preorder(node* root)
{
    if (root == NULL)
        return;

    node* stack[100];
    int top = -1;
    
    stack[++top] = root; // push
    while (top != -1)
    {
        node* curr = stack[top--]; //pop
        printf("%d ",curr->data);

        if (curr->right != NULL)
            stack[++top] = curr->right; //push

        if (curr->left != NULL)
            stack[++top] = curr->left; //push
    }
    printf("\n");
}

void inorder(node* root)
{
    if (root == NULL)
        return;

    node* stack[100];
    int top = -1;
    node* curr = root;
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr; //push
            curr = curr->left;
        }

        curr = stack[top--]; //pop
        printf("%d ",curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void postorder(node* root)
{
    if (root == NULL)
        return;

    // using two stacks

    node* stack[100];
    int result_stack[100];
    int top1 = -1, top2 = -1;
    
    stack[++top1] = root;
    while (top1 != -1)
    {
        node* curr = stack[top1--];
        result_stack[++top2] = curr->data;
        
        if (curr->left != NULL)
            stack[++top1] = curr->left;

        if (curr->right != NULL)
            stack[++top1] = curr->right;
    }

    while (top2 != -1)
    {
        printf("%d ",result_stack[top2--]);
    }
    printf("\n");
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(30);
    root->left->left = newNode(50);
    root->right = newNode(40);
    root->right->left= newNode(20);
    root->right->right = newNode(60);
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}
