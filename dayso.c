#include <stdio.h>

int main() {
	unsigned int n;
	printf("Nhap n = ");
	scanf("%u", &n);
	double a[n];
	for (int i = 0; i < n; ++i) {
		printf("Nhap a[%u] = ", i);
		scanf("%lg", &a[i]);
	}
	unsigned int min_id = 0, max_id = 0, am = 0;
	double tong = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < a[min_id])
			min_id = i;
		if (a[i] > a[max_id])
			max_id = i;
		if (a[i] > 0)
			tong += a[i];
		if (a[i] < 0)
			am++;
	}
	printf("Phan tu nho nhat: %lg\nPhan tu lon nhat: %lg\nTong cac phan tu duong: %lg\nSo phan tu am: %u\n", a[min_id], a[max_id], tong, am);
}