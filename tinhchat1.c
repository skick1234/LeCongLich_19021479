#include <stdio.h>

void Nhap(int (*a)[], unsigned int n);
void Xuat(int a[], unsigned int n);
int NguyenTo(int n);
double SapXep(int (*a)[], unsigned int n);

int main() {
	unsigned int n;
	printf("Nhap so phan tu cua day so: ");
	scanf("%u", &n);
	int a[n];
	Nhap(&a, n);
	Xuat(a, n);
	SapXep(&a, n);
	Xuat(a, n);
	return 0;
}

void Nhap(int (*a)[], unsigned int n) {
	int i, tmp;
	printf("Nhap day so: ");
	for (i = 0; i < n; ++i) {
		scanf("%i", &tmp);
		(*a)[i] = tmp;
	}
}

void Xuat(int a[], unsigned int n) {
	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		if (NguyenTo(a[i]))
			printf("%i ", a[i]);
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

double SapXep(int (*a)[], unsigned int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int max_id = i;
		for (j = i; j < n; j++)
			if ((*a)[j] > (*a)[max_id])
				max_id = j;
		int max = (*a)[max_id];
		(*a)[max_id] = (*a)[i];
		(*a)[i] = max;
	}
}
