//Second largest element
#include<stdio.h>
int main(){
    int n, i, arr[n];
    printf("ENTER THE NUMBER OF ELEMENTS : \n");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS OF THE ARRAY : \n");
    for(i=0;i<n;i++){
    scanf("%d", &arr[i]);}
    int l=arr[0];
    int sl=-1;
    for(i=0;i<n;i++){
        if(arr[i]>l){
            sl=l;
            l = arr[i]; }
        else if(arr[i]>sl && arr[i]!=l){
            sl=arr[i];
        } 
        
    } 
    printf("SECOND LARGEST ELEMENT : %d\n", sl);
    return 0;
}