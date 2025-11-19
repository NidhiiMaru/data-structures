#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int a[] = {12, 11, 15, 10, 1};
const int len = sizeof(a) / sizeof(a[0]);
int p[100];

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            p[k++] = a[i++];
        else
            p[k++] = a[j++];
    }

    while (i <= mid)
    {
        p[k++] = a[i++];
    }

    while (j <= high)
    {
        p[k++] = a[j++];
    }

    // Copy back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = p[k];
}

void mergeSort(int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    merge(low, mid, high);
}

void main()
{
    mergeSort(0, len - 1);

    for (int i = 0; i < len; i++)
        printf("%d\t", a[i]);
}
