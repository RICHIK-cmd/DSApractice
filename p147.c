#include <stdio.h>

int atoiRecursive(char str[], int i, int num)
{
    // Base case: end of string
    if (str[i] == '\0')
        return num;

    // If current character is not a digit
    if (str[i] < '0' || str[i] > '9')
        return -1;

    // Add current digit
    num = num * 10 + (str[i] - '0');

    // Recursive call
    return atoiRecursive(str, i + 1, num);
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Output: %d\n", atoiRecursive(str, 0, 0));

    return 0;
}