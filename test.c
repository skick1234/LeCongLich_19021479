
#include<stdio.h>

void nhap(int a[], int *n){
    scanf("%d", n);
    int i;
    for(i=0;i<*n;i++){
        scanf("%d", &a[i]);
    }
}

void selectionSort(int a[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void xuat(int a[], int n ){
    int i;
     for(i = 0; i < n; i++){
         printf("%5d", a[i]);
    }
     printf("\n");
}

int main(){
    int n;
    int a[10];
    
    nhap(a, &n);
    
    selectionSort(a, n);
    xuat(a, n);
    

    return 0;
}