#include <stdio.h>

void shellSort(int a[], int n)
{
    int gap, i, j, temp;

    for(gap = n / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = a[i];
            j = i;

            while(j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;
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

    shellSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
