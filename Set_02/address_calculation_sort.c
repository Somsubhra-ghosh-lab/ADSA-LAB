#include <stdio.h>

void addressCalculationSort(int a[], int n)
{
    int count[1000] = {0};
    int i, j, k = 0, max = a[0];

    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];

    for(i = 0; i < n; i++)
        count[a[i]]++;

    for(i = 0; i <= max; i++)
    {
        for(j = 0; j < count[i]; j++)
            a[k++] = i;
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    addressCalculationSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
