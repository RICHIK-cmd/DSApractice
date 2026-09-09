#include <stdio.h>
#include <string.h>

void frequencySort(char s[], char ans[])
{
    int freq[256] = {0};
    int n = strlen(s);

    // Step 1: Count frequency of each character
    for (int i = 0; i < n; i++)
    {
        freq[(unsigned char)s[i]]++;
    }

    // Step 2: Store characters that appear
    char chars[256];
    int count = 0;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            chars[count++] = (char)i;
        }
    }

    // Step 3: Sort characters by frequency (decreasing)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (freq[(unsigned char)chars[i]] <
                freq[(unsigned char)chars[j]])
            {
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;
            }
        }
    }

    // Step 4: Build the answer
    int k = 0;

    for (int i = 0; i < count; i++)
    {
        int f = freq[(unsigned char)chars[i]];

        for (int j = 0; j < f; j++)
        {
            ans[k++] = chars[i];
        }
    }

    ans[k] = '\0';
}

int main()
{
    char s[1000];
    char ans[1000];

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    frequencySort(s, ans);

    printf("Frequency sorted string: %s\n", ans);

    return 0;
}