#include <stdio.h>
#include <math.h>

void Nhap(double (*a)[], unsigned int n);
double TrungBinh(double a[], unsigned int n);
double DoLechChuan(double a[], unsigned int n);

int main() {
	unsigned int n;
	printf("Nhap n = ");
	scanf("%u", &n);
	double a[n];
	Nhap(&a, n);
	printf("Ky vong cua day so: %lg\nDo lech chuan cua day so: %lg", TrungBinh(a,n), DoLechChuan(a, n));
	return 0;
}

void Nhap(double (*a)[], unsigned int n) {
	double tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%lg", &tmp);
		(*a)[i] = tmp;
	}
}

double TrungBinh(double a[], unsigned int n) {
	double tong = 0;
	for (int i = 0; i < n; i++)
		tong += a[i];
	return tong/n;
}

double DoLechChuan(double a[], unsigned int n) {
	double tong = 0, u = TrungBinh(a, n);
	for (int i = 0; i < n; i++)
		tong += pow(a[i] - u, 2);
	return sqrt(tong/n);
}