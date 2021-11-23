//Program to delete an element from an array
#include <stdio.h>

int main()
{
    int arr[20]; //maximum array size is 20

    printf("Enter the size of the array(max array size is 20): ");
    int n;
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the position of the element to be deleted : ");
    int pos;
    scanf("%d",&pos);
    
    for(int i=pos;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }

    printf("The array after deletion is: \n");
    for(int i=0;i<n-1;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    return 0;
}