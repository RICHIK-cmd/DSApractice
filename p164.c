#include <stdio.h>
#include <string.h>

void longestCommonPrefix(char strs[][100], int n, char result[])
{
    int len = 0;

    // Compare first string with every other string
    for (int i = 0; i < strlen(strs[0]); i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i] != strs[0][i] || strs[j][i] == '\0')
            {
                result[len] = '\0';
                return;
            }
        }

        result[len] = strs[0][i];
        len++;
    }

    result[len] = '\0';
}

int main()
{
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    char strs[n][100];
    char result[100];

    printf("Enter the strings:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%99s", strs[i]);
    }

    longestCommonPrefix(strs, n, result);

    printf("Longest Common Prefix: %s\n", result);

    return 0;
}