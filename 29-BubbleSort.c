#include <stdio.h>

int main()
{
    int array[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter %d integers\n", n);
    for (int i=0; i<n; i++)
        scanf("%d",&array[i]);
    
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                int swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    printf("Sorted array:\n");
    for (int i =0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}