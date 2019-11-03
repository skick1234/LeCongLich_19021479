#include <stdio.h>
#include <math.h>

void Nhap(int a[], unsigned int n);
void Xuat(int a[], unsigned int n);
int TimPT(int a[], unsigned int n, int x);
void Chen(int a[], unsigned int *n, unsigned int vt, int x);
void Xoa(int a[], unsigned int *n, int x);

int main() {
	unsigned int n;
	printf("Nhap day so\nSo phan tu n = ");
	scanf("%u", &n);
	int a[1000], c, x, vt;
	Nhap(&a, n);
	Xuat(a, n);
	printf("Nhap phan tu muon chen them: ");
	scanf("%i", &c);
	printf("Nhap vi tri chen them: ");
	scanf("%i", &vt);
	Chen(&a, &n, vt, c);
	Xuat(a, n);
	printf("Nhap phan tu muon xoa: ");
	scanf("%i", &x);
	Xoa(&a, &n, x);
	Xuat(a, n);
	return 0;
}

void Nhap(int a[], unsigned int n) {
	int tmp, i;
	printf("Nhap day so: ");
	for (i = 0; i < n; ++i) {
		scanf("%i", &tmp);
		a[i] = tmp;
	}
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

void Xuat(int a[], unsigned int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		if (NguyenTo(a[i]))
			printf("%i ", a[i]);
	printf("\n");
}

int TimPT(int a[], unsigned int n, int x) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}

void Chen(int a[], unsigned int *n, unsigned int vt, int x) {
	int i;
	(*n)++;
	for (i = *n; i > vt; i--)
		a[i] = a[i-1];
	a[vt] = x;
}

void Xoa(int a[], unsigned int *n, int x) {
	int i;
	x = TimPT(*a, *n, x);
	if (x != -1) {
		for (i = x; i < *n; i++)
			a[i] = a[i+1];
		(*n)--;
	}
}

