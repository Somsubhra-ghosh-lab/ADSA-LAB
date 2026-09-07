#include <stdio.h>

void radixExchange(int a[], int left, int right, int bit)
{
    int i = left, j = right, temp;

    if(left >= right || bit < 0)
        return;

    while(i <= j)
    {
        while(i <= j && ((a[i] >> bit) & 1) == 0)
            i++;

        while(i <= j && ((a[j] >> bit) & 1) == 1)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    radixExchange(a, left, j, bit - 1);
    radixExchange(a, i, right, bit - 1);
}

void radixExchangeSort(int a[], int n)
{
    radixExchange(a, 0, n - 1, 30);
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixExchangeSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
