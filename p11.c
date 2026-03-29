// two sum
#include <stdio.h>
void twosum(int arr[], int n, int target)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                c++;
                printf("PAIR FOUND AT INDEX: %d AND %d\n", i, j);
            }
        }
    }
    if (c != 1)
    {
        printf("PAIR NOT FOUND/n");
    }
}
int main()
{
    int i, j, target, n;
    printf("ENTER THE NUMBER OF ELEMENTS: \n");
    scanf("%d", &n);

    int arr[n];

    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("ENTER TARGET : \n");
    scanf("%d", &target);

    twosum(arr, n, target);
    return 0;
}