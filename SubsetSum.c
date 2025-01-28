#include <stdio.h>
#include <stdlib.h>

int equaltosum(int sub[], int len, int target)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += sub[i];
    }
    if (sum == target)
    {
        return 1;
    }
    return 0;
}
void subset(int arr[], int index, int target, int sub[], int len, int n)
{
    if (equaltosum(sub, len, target))
    {
        for (int i = 0; i < len; i++)
        {
            printf("%d ", sub[i]);
        }
        printf("\n");
    }

    for (int i = index; i < n; i++)
    {
        if (i > index && arr[i - 1] == arr[i])
        {
            continue;
        }
        sub[len] = arr[i];
        subset(arr, i + 1, target, sub, len + 1, n);
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int n;
    printf("enter number of elements:\n");
    scanf("%d", &n);
    int arr[n], sub[n];
    printf("enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the target want to search:\n");
    int target;
    scanf("%d", &target);
    qsort(arr, n, sizeof(int), compare);
    printf("Subsets having target: %d\n", target);
    subset(arr, 0, target, sub, 0, n);
    return 0;
}