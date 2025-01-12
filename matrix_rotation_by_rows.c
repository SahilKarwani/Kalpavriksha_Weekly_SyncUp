#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void reverse(int array[], int low, int high)
{
    while (low <= high)
    {
        swap(&array[low++], &array[high--]);
    }
}

void rotationByRows(int **matrix, int rows, int columns, int k)
{

    int array[rows * columns], j = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            array[j++] = matrix[row][col];
        }
    }

    reverse(array, 0, rows * columns - 1);
    reverse(array, 0, k * columns - 1);
    reverse(array, k * columns, rows * columns - 1);

    j = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            matrix[row][col] = array[j++];
        }
    }
}

int main()
{

    int rows, columns, rotationFactor;
    printf("Enter num of rows:\n");
    scanf("%d", &rows);
    printf("Enter num of columns:\n");
    scanf("%d", &columns);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int index = 0; index < rows; index++)
    {
        matrix[index] = (int *)malloc(columns * sizeof(int));
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            printf("Enter element at (%d %d): ", row, col);
            scanf("%d", &matrix[row][col]);
        }
    }

    printf("Enter the rotation factor:\n");
    scanf("%d", &rotationFactor);

    rotationByRows(matrix, rows, columns, rotationFactor);

    printf("Matrix after rotation by rows with factor of %d\n", rotationFactor);
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            printf("%d", matrix[row][col]);
        }
        printf("\n");
    }
}
