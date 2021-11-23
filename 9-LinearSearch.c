#include <stdio.h>
int main()
{
    int arr[20]; //max size of array is 20

    printf("Enter the size of the array (max size =20): ");
    int n;
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search in array: ");
    int key;
    scanf("%d",&key);

    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("Element found at index %d\n",i);
            found=1;
            break;
        }
    }

    if(found==0)
    {
        printf("Element not found\n");
    }
    return 0;
}