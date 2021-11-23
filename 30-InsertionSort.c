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

    for (int i=0; i<n; i++)
    {
        int j = i-1;
        int key = array[i];
        while (j > -1 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    printf("Sorted array:\n");
    for (int i =0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}