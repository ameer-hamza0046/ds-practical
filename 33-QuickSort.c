#include <stdio.h>

int partition(int arr[], int l, int r)
{
    // int pivot = arr[l];

    int pivot = arr[l];
    int p1 = l + 1;

    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[p1];
            arr[p1] = arr[i];
            arr[i] = temp;

            p1++;
        }
    }
    int temp = arr[l];
    arr[l] = arr[p1 - 1];
    arr[p1 - 1] = temp;
    return p1 - 1;
}

void quick_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int p = partition(arr, l, r);
    quick_sort(arr, l, p - 1);
    quick_sort(arr, p + 1, r);
}

int main()
{
    int arr[] = {12, 10, 43, 23, 78, 45, 56, 98, 41, 90, 24};
    int num;
    num = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, num - 1);

    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    return 0;
}