#include <stdio.h>
int main()
{
    int n, i, key;
    printf("ENTER THE NUMBER OF ELEMENTS : \n");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED : \n");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            
            printf("ELEMENT FOUND AT INDEX : %d\n", i);
            break;
        }
    
    } return 0;
}