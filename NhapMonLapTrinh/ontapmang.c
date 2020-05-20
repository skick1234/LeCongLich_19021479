#include <stdio.h>

void Nhap(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("a[%i] = ", i);
        scanf("%i", a+i);
    }
}

void Xuat(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%i ", a[i]);
}

int Tong(int a[], int n) {
    int i, s = 0;
    for (i = 1; i < n; i += 2)
        s += a[i];
    return s;
}

void Daycontang(int a[], int n) {
    int i, max = 0, dem = 0, sum = 0;
    for (i = 0; i < n; i++) {
    }
}
