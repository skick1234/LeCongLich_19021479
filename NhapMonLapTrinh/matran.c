#include <stdio.h>
#include <stdlib.h>

typedef struct Matran {
    int dong, cot;
    double **data;
} Matran;

Matran TaoMT(int dong, int cot){
    Matran mt;
    int i = 0;
    mt.dong = dong;
    mt.cot = cot;
    mt.data = (double **) calloc(dong, sizeof(double *));
    for(i=0;i<dong;i++)
        mt.data[i] = (double *) calloc(cot, sizeof(double));
    return mt;
}

void NhapMT(Matran* mt) {
    int i, j;
    for (i = 0; i < mt->dong; i++)
        for (j = 0; j < mt->cot; j++) {
            printf("[%i][%i] = ", i, j);
            scanf("%lf", &mt->data[i][j]);
        }
}

void XuatMT(Matran mt) {
    int i, j;
    for (i = 0; i < mt.dong; i++) {
        for (j = 0; j < mt.cot; j++)
            printf("%lg\t", mt.data[i][j]);
        printf("\n");
    }
}

Matran TichMT(Matran mt1, Matran mt2) {
    if (mt1.cot != mt2.dong) {
        return (Matran) {0, 0, NULL};
    } else {
        Matran mt = TaoMT(mt1.dong, mt2.cot);
        int i, j, k;
        for (i = 0; i < mt.dong; i++)
            for (j = 0; j < mt.cot; j++) {
                mt.data[i][j] = 0;
                for (k = 0; k < mt1.cot; k++)
                    mt.data[i][j] += mt1.data[i][k] * mt2.data[k][j];
            }
        return mt;
    }
}

double TongPT(Matran mt) {
    int i, j;
    double sum = 0;
    for (i = 0; i < mt.dong; i++)
        for (j = 0; j < mt.cot; j++)
            sum += mt.data[i][j];
    return sum;
}

void InDuongCheo(Matran mt) {
    if (mt.dong != mt.cot)
        printf("Ma tran khong co duong cheo chinh\n");
    else {
        int i;
        for (i = 0; i < mt.dong; i++)
            printf("%lg\t", mt.data[i][i]);
        printf("\n");
    }
}

int main() {
    int dong, cot;
    printf("Nhap ma tran 1:\nNhap so dong = ");
    scanf("%i", &dong);
    printf("Nhap so cot = ");
    scanf("%i", &cot);
    Matran mt1 = TaoMT(dong, cot);
    NhapMT(&mt1);
    printf("Nhap ma tran 2:\nNhap so dong = ");
    scanf("%i", &dong);
    printf("Nhap so cot = ");
    scanf("%i", &cot);
    Matran mt2 = TaoMT(dong, cot);
    NhapMT(&mt2);
    printf("\nMa tran 1 la:\n");
    XuatMT(mt1);
    printf("Ma tran 2 la:\n");
    XuatMT(mt2);
    printf("Ma tran tich cua 1 va 2 la:\n");
    if (mt1.cot != mt2.dong)
        printf("Khong ton tai.");
    else
        XuatMT(TichMT(mt1, mt2));
    printf("Tong cac phan tu cua ma tran 1 la: %lg\n", TongPT(mt1));
    printf("Cac phan tu nam tren duong cheo chinh cua ma tran 2 la:\n");
    InDuongCheo(mt2);
    return 0;
}
