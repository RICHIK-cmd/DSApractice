#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool rotateString(char s[], char goal[])
{
    int n = strlen(s);
    int m = strlen(goal);

    // Step 1: Lengths must be equal
    if (n != m)
        return false;

    // Step 2: Create s + s
    char concat[200];

    strcpy(concat, s);
    strcat(concat, s);

    // Step 3: Check if goal is a substring of concat
    if (strstr(concat, goal) != NULL)
        return true;

    return false;
}

int main()
{
    char s[100];
    char goal[100];

    printf("Enter string s: ");
    scanf("%s", s);

    printf("Enter goal string: ");
    scanf("%s", goal);

    if (rotateString(s, goal))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}