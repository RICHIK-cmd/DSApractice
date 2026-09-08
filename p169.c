#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char s[], char t[])
{
    int freq[256] = {0};

    // Count characters in s
    for (int i = 0; s[i] != '\0'; i++)
        freq[(unsigned char)s[i]]++;

    // Remove characters using t
    for (int i = 0; t[i] != '\0'; i++)
    {
        freq[(unsigned char)t[i]]--;

        // More occurrences in t than in s
        if (freq[(unsigned char)t[i]] < 0)
            return false;
    }

    // Check if anything is left from s
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    char s[1000], t[1000];

    printf("Enter string s: ");
    scanf("%999s", s);

    printf("Enter string t: ");
    scanf("%999s", t);

    if (isAnagram(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}