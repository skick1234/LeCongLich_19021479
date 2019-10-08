#include <stdio.h>
#include <math.h>

void Nhap(double (*a)[], unsigned int n);
void Xuat(double a[], unsigned int n);
int Search(double a[], unsigned int n, double x);
double SapXep(double (*a)[], unsigned int n);

int main() {
	unsigned int n;
	printf("Nhap day so\nSo phan tu n = ");
	scanf("%u", &n);
	double a[n], x;
	Nhap(&a, n);
	Xuat(a, n);
	printf("\nNhap so can tim x = ");
	scanf("%lg", x);
	int s = Search(a, n, x);
	if (s == -1)
		printf("Khong tim thay so %lg.\n", x);
	else
		printf("So %lg xuat hien o a[%u]\n", x, s);
	SapXep(&a, n);
	Xuat(a, n);
	return 0;
}

void Nhap(double (*a)[], unsigned int n) {
	double tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%lg", &tmp);
		(*a)[i] = tmp;
	}
}

void Xuat(double a[], unsigned int n) {
	for (int i = 0; i < n; i++)
		printf("%lg ", a[i]);
}

int Search(double a[], unsigned int n, double x) {
	for (int i = 0; i < n; i++)
		if (x == a[i])
			return i;
	return -1;
}

double SapXep(double (*a)[], unsigned int n) {
	for (int i = 0; i < n; i++) {
		int min_id = i;
		for (int j = i; j < n; j++)
			if ((*a)[j] < (*a)[min_id])
				min_id = j;
		int min = (*a)[min_id];
		(*a)[min_id] = (*a)[i];
		(*a)[i] = min;
	}
}