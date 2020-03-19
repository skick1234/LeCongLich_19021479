#include<stdio.h>
#define MAX 10

void nhap(int arr[]){
    int i;
    for(i=0;i<MAX;i++){
        scanf("%d", &arr[i]);
    }
}

void hienThi(const int arr[]){
    int i;
    for(i=0;i<MAX;i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[]){
    int i,j;
    for(i=0;i<MAX-1;i++){
        for(i=MAX-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                int tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
            }
        }
    }
}

int main(){
    int arr(MAX);
    nhap(arr);
    hienThi(arr);
    bubbleSort(arr);
    hienThi(arr);

    return 0;
}
