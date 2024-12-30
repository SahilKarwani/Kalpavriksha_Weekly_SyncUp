#include <stdio.h>
#include <string.h>

void caseConversion(char *inputString, char *caseConvertedString)
{

    int stringLength = 0;
    int counter = 0;
    while (inputString[counter] != '\0')
    {
        counter++;
    }
    stringLength = counter;
    for (int index = 0; index < stringLength; index++)
    {
        if (inputString[index] >= 'a' && inputString[index] <= 'z')
        {
            caseConvertedString[index] = inputString[index] - 32;
        }
        else if (inputString[index] >= 'A' && inputString[index] <= 'Z')
        {
            caseConvertedString[index] = inputString[index] + 32;
        }
        else
        {
            caseConvertedString[index] = inputString[index];
        }
    }
    caseConvertedString[counter] = '\0';
}

int main()
{

    printf("Enter the string for case conversion:\n");
    char inputString[100], caseConvertedString[100];
    scanf("%s", inputString);

    caseConversion(inputString, caseConvertedString);
    
    printf("Case converted string: ");
    printf("%s", caseConvertedString);

    return 0;
}