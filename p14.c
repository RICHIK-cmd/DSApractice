// array sum using recursion
#include<stdio.h>
int sumarray(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}
int main() {
    int n, i,sum;
    printf("ENTER THE NUMBER OF ELEMENTS : \n");
    scanf("%d", &n); int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("SUM OF THE ARRAY ELEMENTS :%d\n", sumarray(arr, n));
    return 0;
}