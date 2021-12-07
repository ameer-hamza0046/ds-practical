#include <stdio.h>

void merge(int [], int [], int, int, int);
void mergesort(int a[], int b[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, b, low, mid);
        mergesort(a, b, mid + 1, high);
        merge(a, b, low, mid, high);
    }
}

int main()
{
    int a[] = {12, 10, 43, 23, 78, 45, 56, 98, 41, 90, 24};
    int num;
    num = sizeof(a) / sizeof(int);
    int b[100];
    mergesort(a, b, 0, num - 1);
    for (int i = 0; i < num; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void merge(int a[], int b[], int low, int pivot, int high)
{
    int h, i, j, k;
    h = low;
    i = low;
    j = pivot + 1;
    while ((h <= pivot) && (j <= high))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > pivot)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= pivot; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
        a[k] = b[k];
}
