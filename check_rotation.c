#include <stdio.h>

int checkRotation(char *string1, char *string2, int stringLength1, int stringLength2)
{
    for (int i = 0; i < stringLength1; i++)
    {
        int j;
        for (j = 0; j < stringLength2; j++)
        {
            if (string1[(i + j) % stringLength1] != string2[j])
            {
                break;
            }
        }
        if (j == stringLength2)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    char string1[100], string2[100];
    printf("Enter first string: ");
    scanf("%s", &string1);
    printf("Enter second string: ");
    scanf("%s", &string2);
    int stringLength1 = 0, stringLength2 = 0;
    while (string1[stringLength1] != '\0')
    {
        stringLength1++;
    }
    while (string2[stringLength2] != '\0')
    {
        stringLength2++;
    }
    if (stringLength1 == 0 && stringLength2 == 0)
    {
        printf("Two strings are rotation of each other or not: ");
        printf("YES");
        return 1;
    }
    if (stringLength1 == 0 || stringLength2 == 0 || stringLength1 != stringLength2)
    {
        printf("Two strings are rotation of each other or not: ");
        printf("NO");
        return 0;
    }
    int rotateOrNot = checkRotation(string1, string2, stringLength1, stringLength2);
    printf("Two strings are rotation of each other or not: ");
    if (rotateOrNot == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}