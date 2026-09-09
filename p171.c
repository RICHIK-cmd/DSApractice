#include <stdio.h>
#include <string.h>

int maxDepth(char s[])
{
    int opened = 0;
    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            opened++;

            if (opened > ans)
                ans = opened;
        }
        else if (s[i] == ')')
        {
            opened--;
        }
    }

    return ans;
}

int main()
{
    char s[1000];

    printf("Enter the VPS: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    int result = maxDepth(s);

    printf("Maximum nesting depth = %d\n", result);

    return 0;
}