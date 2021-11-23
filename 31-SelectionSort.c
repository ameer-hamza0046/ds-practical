#include <stdio.h>
#include <limits.h>

int main()
{
    int array[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter %d integers\n", n);
    for (int i=0; i<n; i++)
        scanf("%d",&array[i]);

    int minelement, minidx;
    for (int i=0; i<n-1; i++)
    {
        minelement = INT_MAX; 
        for (int j = i; j<n; j++)
        {
            if (array[j] < minelement)
            {
                minelement = array[j];
                minidx = j;
            }
        }
        int swap = array[minidx];
        array[minidx] = array[i];
        array[i] = swap;
    }

    printf("Sorted array:\n");
    for (int i =0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}