#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mapping[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void solve(char digits[], int index, char temp[], int tempIndex)
{
    // Base case:
    // We have selected one letter for every digit
    if (digits[index] == '\0')
    {
        temp[tempIndex] = '\0';
        printf("\"%s\" ", temp);
        return;
    }

    // Get the current digit
    int digit = digits[index] - '0';

    // Get letters corresponding to the digit
    char *letters = mapping[digit];

    // Try every possible letter
    for (int i = 0; letters[i] != '\0'; i++)
    {
        // Choose
        temp[tempIndex] = letters[i];

        // Move to the next digit
        solve(digits, index + 1, temp, tempIndex + 1);

        // Backtracking happens automatically
        // when temp[tempIndex] is overwritten
        // by the next letter
    }
}

int main()
{
    char digits[20];
    char temp[20];

    printf("Enter digits (2-9): ");
    scanf("%s", digits);

    if (strlen(digits) == 0)
    {
        printf("[]");
        return 0;
    }

    printf("Output: [");

    solve(digits, 0, temp, 0);

    printf("]\n");

    return 0;
}