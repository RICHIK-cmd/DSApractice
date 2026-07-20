#include <stdio.h>
int main() {
    int n, i;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d", &n);
    int arr[n-1];
    printf("ENTER THE ARRAY ELEMENTS : \n");
    for(i=0;i<n-1;i++){
        scanf("%d", &arr[i]);
    } //1 2  4 5 6 7 8 9 
    int expected_sum=n*(n+1)/2;
    int actual_sum=0;
    for(i=0;i<n-1;i++){
        actual_sum=+arr[i];
    }
    int missing=expected_sum-actual_sum;
    printf("MISSING NUMBER IS : %d\n", missing);
    return 0;
}