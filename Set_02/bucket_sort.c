#include <stdio.h>

void bucketSort(int a[], int n)
{
    int bucket[10][100], count[10] = {0};
    int i, j, k, index, temp, pos = 0;

    for(i = 0; i < n; i++)
    {
        index = a[i] / 10;
        bucket[index][count[index]++] = a[i];
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < count[i] - 1; j++)
        {
            for(k = j + 1; k < count[i]; k++)
            {
                if(bucket[i][j] > bucket[i][k])
                {
                    temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    for(i = 0; i < 10; i++)
        for(j = 0; j < count[i]; j++)
            a[pos++] = bucket[i][j];
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements (0-99): ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
