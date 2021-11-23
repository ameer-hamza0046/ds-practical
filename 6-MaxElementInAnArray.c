//Program to find the largest element in the array
#include <stdio.h>
int main()
{
    int arr[20]; //max size of array is 20
    printf("Enter the number of elements in the array (max = 20): ");
    int n;
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int large=arr[0], pos=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
            pos = i;
        }
    }

    printf("The smallest element in the array is %d which is present at index %d\n",large,pos);
    return 0;
}