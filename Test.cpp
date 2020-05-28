#include<stdio.h>

void nhap(int a[50][50], int *m, int *n){
    scanf("%d %d", m,n);
    int i,j;
    for(i=0;i<*m;i++){
        for(j=0;j<*n;j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void chuyenVi(int a[50][50],int m, int n, int b[50][50]){
    int i,j;
    for(i=0;j<m;i++){
        for(j=0;j<n;j++){
            a[i][j] = b[j][i];
        }
    }
}

void nhan(int a[][50], int b[][50], int c[][50], int m, int n, int k){
    int i,j,l;
    for(i=0;i<m;i++)
        for(j=0;j<k;j++){
            c[i][j] = 0;
            for(l=0;l<n;l++){
                c[i][j] += a[i][l] * b[l][k];
            }
        }
}

void hienThi(int arr[50][50], int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a[50][50], b[50][50], c[50][50] = {0};
    int ma, na, mb, nb;

    nhap(a,&ma,&na);
    hienThi(a,ma,na);

    chuyenVi(a,ma,nb,b);
    hienThi(b, mb,nb);

    printf("\n");
    nhan(a,b,c,ma,na,mb);
    hienThi(c,ma,nb);

    return 0;
}
