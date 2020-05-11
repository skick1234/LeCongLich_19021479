#include <stdio.h>
#define max 100

int NguyenTo(int n) {
    if (n <= 1)
        return 0;

    int i;
    for (i = 2; i <= n/2; i++)
        if (n%i == 0)
            return 0;

    return 1;
}

void Nhap(int a[][max], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &a[i][j]);
        }
    printf("\n");
}

void Xuat(int a[][max], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%i ", a[i][j]);
        printf("\n");
    }
}

int main() {
    int m, n, a[max][max], i, j;
    printf("Nhap so hang m = ");
    scanf("%i", &m);
    printf("Nhap so cot n = ");
    scanf("%i", &n);
    Nhap(a, m, n);
    printf("\nMang vua nhap la:\n");
    Xuat(a, m, n);
    int max_nt = -1;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (NguyenTo(a[i][j]) && a[i][j] > max_nt)
                max_nt = a[i][j];
    if (max_nt == -1)
        printf("Khong tim thay so nguyen to lon nhat trong mang.");
    else
        printf("So nguyen to lon nhat trong mang: %i", max_nt);
    return 0;
}
