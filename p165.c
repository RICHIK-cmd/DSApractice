#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char s[], char t[])
{
    int mapS[256] = {0};
    int mapT[256] = {0};

    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        // If s[i] is already mapped to a different character
        if (mapS[(unsigned char)s[i]] != 0 &&
            mapS[(unsigned char)s[i]] != (unsigned char)t[i])
        {
            return false;
        }

        // If t[i] is already mapped from a different character
        if (mapT[(unsigned char)t[i]] != 0 &&
            mapT[(unsigned char)t[i]] != (unsigned char)s[i])
        {
            return false;
        }

        // Create the mappings
        mapS[(unsigned char)s[i]] = (unsigned char)t[i];
        mapT[(unsigned char)t[i]] = (unsigned char)s[i];
    }

    return true;
}

int main()
{
    char s[100];
    char t[100];

    printf("Enter string s: ");
    scanf("%s", s);

    printf("Enter string t: ");
    scanf("%s", t);

    if (strlen(s) != strlen(t))
    {
        printf("Not Isomorphic\n");
    }
    else if (isIsomorphic(s, t))
    {
        printf("Isomorphic\n");
    }
    else
    {
        printf("Not Isomorphic\n");
    }

    return 0;
}