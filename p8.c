//left rotate by 1
#include<stdio.h>
int main() {
    int n, i, j=0, temp, r, first;
    printf("ENTER THE NUMBER OF ELEMENTS : \n");
    scanf("%d", &n); int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("ORIGINAL ARRAY : \n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n ENTER THE NUMBER OF LEFT ROTATIONS IN THE ARRAY : \n");
    scanf("%d", &r);
    for(int j=0;j<r;j++){
        first = arr[0];
        for(i=0;i<n-1;i++){
            arr[i]=arr[i+1];
           
        }  arr[n-1]=first;
    }
    printf("ARRAY AFTER LEFT ROTATIONS : \n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
