#include <stdio.h>
#include <math.h>

void Nhap(double (*a)[], unsigned int n);
void Xuat(double a[], unsigned int n);
int Tim(double a[], unsigned int n, double x);
void SapXep(double (*a)[], unsigned int n);

int main() {
	unsigned int n;
	printf("Nhap day so\nSo phan tu n = ");
	scanf("%u", &n);
	double a[n];
	Nhap(&a, n);
	printf("Day so vua nhap: ");
	Xuat(a, n);
	double x;
	printf("Nhap so can tim x = ");
	scanf("%lg", &x);
	int s = Tim(a, n, x);
	if (s == -1)
		printf("Khong tim thay so %lg.\n", x);
	else
		printf("So %lg xuat hien o a[%u]\n", x, s);
	SapXep(&a, n);
	printf("Day so da sap xep: ");
	Xuat(a, n);
	return 0;
}

void Nhap(double (*a)[], unsigned int n) {
	double tmp;
	int i;
	printf("Nhap day so: ");
	for (i = 0; i < n; ++i) {
		scanf("%lg", &tmp);
		(*a)[i] = tmp;
	}
}

void Xuat(double a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%lg ", a[i]);
	printf("\n");
}

int Tim(double a[], unsigned int n, double x) {
	int j;
	for (j = 0; j < n; j++)
		if (a[j] == x)
			return j;
	return -1;
}

void SapXep(double (*a)[], unsigned int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min_id = i;
		for (j = i; j < n; j++)
			if ((*a)[j] < (*a)[min_id])
				min_id = j;
		double min = (*a)[min_id];
		(*a)[min_id] = (*a)[i];
		(*a)[i] = min;
	}
}

