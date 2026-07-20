#include <stdio.h>
int main()
{
    int n, i;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum=sum+arr[i];
    }
    printf("SUM OF THE ARRAY ELEMENTS :%d\n", sum);
    return 0;
}