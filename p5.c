//move all 00s to the end
#include<stdio.h>
int main() {
    int n, i, j=0, temp;
    printf("ENTER THE NUMBER OF ELEMENTS : \n");
    scanf("%d", &n); int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(i=0; i<n; i++){
        if(arr[i]!=0){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
    printf("ARRAY UPDATED : \n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}