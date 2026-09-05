#include <stdio.h>
#include <string.h>

void removeOuterParentheses(char s[], char res[])
{
    int opened = 0;
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            if (opened > 0)
            {
                res[j++] = s[i];
            }

            opened++;
        }
        else
        {
            opened--;

            if (opened > 0)
            {
                res[j++] = s[i];
            }
        }
    }

    res[j] = '\0';
}

int main()
{
    char s[1000];
    char res[1000];

    printf("Enter valid parentheses string: ");
    scanf("%s", s);

    removeOuterParentheses(s, res);

    printf("Result: %s\n", res);

    return 0;
}