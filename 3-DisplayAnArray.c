//Taking an array as input and displaying it
#include <stdio.h>
int main()
{
    int arr[10];
    printf("Enter the size of the array (max array size =10): ");
    int n;
    scanf("%d",&n);

    printf("Enter the elements of the array one by one: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}