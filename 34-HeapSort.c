#include <stdio.h>

#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)
#define parent(i) ((i - 1) / 2)

void max_heapify(int arr[], int n, int i)
{
    int l = left(i), r = right(i), largest;

    if (l < n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (i != largest)
    {
        // swap
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n)
{
    for (int i = parent(n - 1); i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n)
{
    build_max_heap(arr, n);

    int i = n - 1;
    while (i > 0)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        n--;
        max_heapify(arr, n, 0);
        i--;
    }
}

int main()
{
    int arr[] = {12, 10, 43, 23, 78, 45, 56, 98, 41, 90, 24};
    int num;
    num = sizeof(arr) / sizeof(int);
    heap_sort(arr, num);
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    return 0;
}
