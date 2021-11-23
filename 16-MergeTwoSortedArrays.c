#include <stdio.h>

int main()
{
    int arr1[20],arr2[20],arr3[40];
    int n1,n2;
    printf("Enter the size of the first array: ");
    scanf("%d",&n1);
    printf("Enter the elements of the first sorted array: ");
    for(int i=0;i<n1;i++)
        scanf("%d",&arr1[i]);

    printf("Enter the size of the second array: ");
    scanf("%d",&n2);
    printf("Enter the elements of the second sorted array: ");
    for(int i=0;i<n2;i++)
        scanf("%d",&arr2[i]);

    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }

    printf("After merging the sorted arrays, the resultant array is: \n");
    for(int x=0;x<n1+n2;x++)
        printf("%d ",arr3[x]);
    return 0;
}