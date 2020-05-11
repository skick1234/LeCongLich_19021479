#include <stdio.h>

void NhapMTV(double* mt, int kt) {
    int i, j;
    for (i = 0; i < kt; i++)
        for (j = 0; j < kt; j++) {
            printf("[%i][%i] = ", i, j);
            scanf("%lf", (mt+i*kt+j));
        }
}

void XuatMTV(double* mt, int kt) {
    int i, j;
    for (i = 0; i < kt; i++) {
        for (j = 0; j < kt; j++)
            printf("%lg\t", *(mt+i*kt+j));
        printf("\n");
    }
}

void ChuyenViMTV(double* mt, int kt) {
    int i, j;
    double tmp;
    for (i = 0; i < kt; i++)
        for (j = i+1; j < kt; j++)  {
            tmp = *(mt+i*kt+j);
            *(mt+i*kt+j) = *(mt+j*kt+i);
            *(mt+j*kt+i) = tmp;
        }
}

double TongDuongCheo(double* mt, int kt) {
    double sum = 0;
    for (int i = 0; i < kt; ++i)
        sum += *(mt+i*(kt+1)) + *(mt+(i+1)*(kt-1));
    return sum;
}

int main() {
    int kt;
    printf("Nhap kich thuoc ma tran: ");
    scanf("%i", &kt);
    double mt[kt][kt];
    NhapMTV(mt, kt);
    printf("\nMa tran vua nhap la:\n");
    XuatMTV(mt, kt);
    printf("\nMa tran chuyen vi la:\n");
    ChuyenViMTV(mt, kt);
    XuatMTV(mt, kt);
    printf("\nTong cac phan tu tren duong cheo la: %lg\n", TongDuongCheo(mt, kt));
    return 0;
}
