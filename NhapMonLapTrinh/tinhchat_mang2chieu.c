#include <stdio.h>
#include <math.h>

int ChinhPhuong(int n) {
    return ((int) sqrt(n) == sqrt(n) ? 1 : 0);
}

void Nhap(int *a, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", (a+i*n+j));
        }
    printf("\n");
}

void Xuat(int *a, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%i\t", *(a+i*n+j));
        printf("\n");
    }
}

void XuatCP(int *a, int m, int n) {
    int i;
    for (i = 0; i < m*n; i++)
        if (ChinhPhuong(*(a+i)))
            printf("%i\t", *(a+i));
    printf("\n");
}

int TimMax(int *a, int m, int n) {
    int ma = *a, i;
    for (i = 1; i < m*n; i++)
        if (*(a+i) > ma)
            ma = *(a+i);
    return ma;
}

int TimMin(int *a, int m, int n) {
    int min = *a, i;
    for (i = 1; i < m*n; i++)
        if (*(a+i) < min)
            min = *(a+i);
    return min;
}

void SapXep(int *a, int m, int n) {
    int tmp, i, j, min_id;
    for (i = 0; i < m*n; i++) {
        min_id = i;
        for (j = i; j < m*n; j++) {
            if (*(a+j) < *(a+min_id))
                min_id = j;
        }
        tmp = *(a+min_id);
        *(a+min_id) = *(a+i);
        *(a+i) = tmp;
    }
}

int main() {
    int m, n;
    printf("Nhap so hang m = ");
    scanf("%i", &m);
    printf("Nhap so cot n = ");
    scanf("%i", &n);
    int a[m][n];
    Nhap(a, m, n);
    printf("\nMang vua nhap la:\n");
    Xuat(a, m, n);
    printf("Cac so chinh phuong cua mang la:\n");
    XuatCP(a, m, n);
    printf("Phan tu lon nhat la: %i\n", TimMax(a, m, n));
    printf("Phan tu be nhat la: %i\n", TimMin(a, m, n));
    SapXep(a, m, n);
    printf("Mang sau khi sap xep la:\n");
    Xuat(a, m, n);
    return 0;
}
