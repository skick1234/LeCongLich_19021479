#include <stdio.h>
#include <math.h>

void Nhap(int a[], unsigned int n);
void Xuat(int a[], unsigned int n);
int SoChan(int n);
void XuatChan(int a[], unsigned int n);
double CanTongChan(int a[], unsigned int n);
int NguyenTo(int n);
void XuatNT(int a[], unsigned int n);
void SapXep(int a[], unsigned int n);
void Chen(int a[], unsigned int n, unsigned int vt, int x);
int Tim(int a[], unsigned int n, int x);
void Xoa(int a[], unsigned int n, int x);

int main() {
	int n;
	do {
		printf("Nhap so phan tu n ( n>0 ): ");
		scanf("%i", &n);
	} while (n <= 0);
	int a[n+1], b[n], i, x, vt;
	printf("Nhap day so: ");
	Nhap(a, n);
	Xuat(a, n);
	printf("Cac phan tu chan lon hon 10:\n");
	XuatChan(a, n);
	printf("\nCan bac hai cua tong cac so chan la:\n");
	if (CanTongChan(a, n) != -1)
		printf("%lg\n", CanTongChan(a, n));
	else
		printf("Khong ton tai\n");
	printf("\nCac phan tu la so nguyen to le la:\n");
	XuatNT(a, n);
	for (i = 0; i < n; i++)
		b[i] = a[i];
	SapXep(b, n);
	printf("\nDay so tang dan la:\n");
	Xuat(b, n);
	printf("\nPhan tu lon nhat = %i\nPhan tu be nhat = %i\n", b[n-1], b[0]);
	printf("\nNhap phan tu can chen them: ");
	scanf("%i", &x);
	printf("Nhap vi tri can chen them (0 - %i): ", n);
	scanf("%i", &vt);
	if (vt <= n && vt >= 0)
		Chen(a, ++n, vt, x);
	printf("\nDay so sau khi chen la: \n");
	Xuat(a, n);
	printf("\nNhap phan tu muon xoa: ");
	scanf("%i", &x);
	if (Tim(a, n, x) != -1)
		Xoa(a, n--, x);
	printf("\nDay so sau khi xoa phan tu %i la:\n", x);
	Xuat(a, n);
	return 0;
}

void Nhap(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		scanf("%i", &a[i]);
}

void Xuat(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%i ", a[i]);
	printf("\n");
}

int SoChan(int n) {
	return (n%2 == 0 ? 1 : 0);
}
	
void XuatChan(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		if (SoChan(a[i]) && a[i] > 10)
			printf("%i ", a[i]);
	printf("\n");
}

double CanTongChan(int a[], unsigned int n) {
	int i, s = 0;
	for (i = 0; i < n; i++)
		if (SoChan(a[i]))
			s += a[i];
	if (s>=0)
		return sqrt(s);
	return -1;
}

int NguyenTo(int n) {
	int i;
	if (n <= 1)
		return 0;
	for (i = 2; i <= n/2; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

void XuatNT(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		if (NguyenTo(a[i]) && !SoChan(a[i]))
			printf("%i ", a[i]);
	printf("\n");
}

void SapXep(int a[], unsigned int n) {
	unsigned int i, j, min_id, tmp;
	for (i = 0; i < n; i++) {
		min_id = i;
		for (j = i; j < n; j++)
			if (a[j] < a[min_id])
				min_id = j;
		tmp = a[i];
		a[i] = a[min_id];
		a[min_id] = tmp;
	}
}

void Chen(int a[], unsigned int n, unsigned int vt, int x) {
	int i;
	for (i = n; i > vt; i--)
		a[i] = a[i-1];
	a[vt] = x;
}

int Tim(int a[], unsigned int n, int x) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}

void Xoa(int a[], unsigned int n, int x) {
	int i;
	x = Tim(a, n, x);
	if (x != 1)
		for (i = x; i < n-1; i++)
			a[i] = a[i+1];
}
