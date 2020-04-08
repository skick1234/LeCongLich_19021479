#include <stdio.h>

void Nhap(float* a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        do {
            printf("a[%i] = ", i);
            scanf("%f", (a+i));
            if (*(a+i) <= 0) printf("Khong phai la so duong\n");
        } while (*(a+i) <= 0);
    }
}

void Xuat(float* a, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%g ", *(a+i));
}

float Tong(float* a, int n) {
    int i;
    float s = 0;
    for (i = 0; i < n; i++)
        s += *(a+i);
    return s;
}

float Min(float* a, int n) {
    int i;
    float min = *a;
    for (i = 1; i < n; i++)
        if (*(a+i) < min) min = *(a+i);
    return min;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%i", &n);
    float a[n];
    Nhap(a, n);
    printf("\nMang vua nhap la:\n");
    Xuat(a, n);
    printf("\nPhan tu nho nhat la: %g\n", Min(a, n));
    printf("Tong cac phan tu la: %g\n", Tong(a, n));
    return 0;
}