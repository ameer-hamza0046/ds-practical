#include <stdio.h>

int main()
{
    int arr[20]; //max size of array is 20

    printf("Enter the size of the array (max size =20): ");
    int n;
    scanf("%d",&n);

    printf("Enter the elements of the sorted array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search in array: ");
    int key;
    scanf("%d",&key);

    int first=0,last=n-1;
    
    while(first<=last)
    {
        int mid = (first+last)/2;
        if(arr[mid]==key)
        {
            printf("Element %d found at index %d\n",key,mid);
            break;
        }
        else if(key<arr[mid])
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    
    if(first>last)
    {
        printf("Element not found\n");
    }
    return 0;
}