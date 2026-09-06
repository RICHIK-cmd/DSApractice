#include <stdio.h>
#include <string.h>

void reverseWords(char s[], char ans[])
{
    int n = strlen(s);
    int i = n - 1;
    int j = 0;

    while (i >= 0)
    {
        // Ignore spaces from the right
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        // Find the beginning of the word
        int end = i;

        while (i >= 0 && s[i] != ' ')
            i--;

        int start = i + 1;

        // Add a space before every word except the first one
        if (j > 0)
            ans[j++] = ' ';

        // Copy the word into ans
        for (int k = start; k <= end; k++)
        {
            ans[j++] = s[k];
        }
    }

    ans[j] = '\0';
}

int main()
{
    char s[1000];
    char ans[1000];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets()
    s[strcspn(s, "\n")] = '\0';

    reverseWords(s, ans);

    printf("Reversed words: %s\n", ans);

    return 0;
}