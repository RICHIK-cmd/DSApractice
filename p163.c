#include <stdio.h>
#include <string.h>

void largestOddNumber(char num[], char result[])
{
    int n = strlen(num);
    int i;
    int j;

    // Start from the last digit
    for (i = n - 1; i >= 0; i--)
    {
        // Check if current digit is odd
        if ((num[i] - '0') % 2 != 0)
        {
            // Copy characters from beginning
            // up to index i
            for (j = 0; j <= i; j++)
            {
                result[j] = num[j];
            }

            // Add null character
            result[j] = '\0';

            return;
        }
    }

    // No odd digit found
    result[0] = '\0';
}

int main()
{
    char num[1000];
    char result[1000];

    printf("Enter the number: ");
    scanf("%s", num);

    largestOddNumber(num, result);

    printf("Largest odd number: %s\n", result);

    return 0;
}