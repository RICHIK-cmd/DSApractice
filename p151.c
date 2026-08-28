#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char *str, int pos, int open, int close, int n)
{
    // If the string is complete
    if (pos == 2 * n)
    {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }

    // Add '(' if we still have opening brackets left
    if (open < n)
    {
        str[pos] = '(';
        generate(str, pos + 1, open + 1, close, n);
    }

    // Add ')' only if it will keep the parentheses valid
    if (close < open)
    {
        str[pos] = ')';
        generate(str, pos + 1, open, close + 1, n);
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    char *str = (char *)malloc((2 * n + 1) * sizeof(char));

    generate(str, 0, 0, 0, n);

    free(str);

    return 0;
}