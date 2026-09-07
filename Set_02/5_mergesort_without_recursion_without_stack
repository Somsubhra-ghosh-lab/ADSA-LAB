#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int b[100], i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= high)
        b[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSortBottomUp(int a[], int n)
{
    int size, low, mid, high;

    for(size = 1; size < n; size *= 2)
    {
        for(low = 0; low < n - size; low += 2 * size)
        {
            mid = low + size - 1;
            high = low + 2 * size - 1;

            if(high >= n)
                high = n - 1;

            merge(a, low, mid, high);
        }
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSortBottomUp(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
