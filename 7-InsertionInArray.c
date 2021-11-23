//Program to insert an element in the array
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

    printf("Enter the number to be inserted: ");
    int num;
    scanf("%d",&num);
    
    printf("Enter the position at which the number is to be inserted: ");
    int pos;
    scanf("%d",&pos);
    
    for(int i=n-1;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=num;

    printf("The array after insertion is: \n");
    for(int i=0;i<n+1;i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    return 0;
}