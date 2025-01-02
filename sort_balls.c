
#include <stdio.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void sortBalls(int arrSize, int arr[])
{
    int low = 0, mid = 0, high = arrSize - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[mid++], &arr[low++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid], &arr[high--]);
        }
    }
}

int main()
{
    // Write C code here
    int arrSize;
    printf("Input the size:\n");
    scanf("%d", &arrSize);
    int arr[arrSize];
    printf("Input: ");
    for (int index = 0; index < arrSize; index++)
    {
        scanf("%d", &arr[index]);
    }

    sortBalls(arrSize, arr);

    printf("After arranging: ");
    for (int index = 0; index < arrSize; index++)
    {
        printf("%d ", arr[index]);
    }

    return 0;
}