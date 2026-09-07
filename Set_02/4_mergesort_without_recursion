#include <stdio.h>

typedef struct
{
    int low, high, state;
} Node;

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

void mergeSortStack(int a[], int n)
{
    Node stack[100];
    int top = -1;

    stack[++top] = (Node){0, n - 1, 0};

    while(top >= 0)
    {
        int low = stack[top].low;
        int high = stack[top].high;
        int state = stack[top].state;
        int mid = (low + high) / 2;

        if(low >= high)
        {
            top--;
            continue;
        }

        if(state == 0)
        {
            stack[top].state = 1;
            stack[++top] = (Node){low, mid, 0};
        }
        else if(state == 1)
        {
            stack[top].state = 2;
            stack[++top] = (Node){mid + 1, high, 0};
        }
        else
        {
            merge(a, low, mid, high);
            top--;
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

    mergeSortStack(a, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
