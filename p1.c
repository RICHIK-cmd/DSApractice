#include <stdio.h>
int main() {
    int n, i;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ARRAY ELEMENTS : \n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int largest=arr[0];
    for(i=1;i<=n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    printf("LARGEST ELEMENT IN THE ARRAY : %d\n", largest);
    return 0;
}