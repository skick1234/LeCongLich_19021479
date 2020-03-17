#include <stdio.h>

void Nhap(int a[], unsigned int n) {
	int i;
	for(i = 0; i < n; i++)
		scanf("%i", (a+i));
}

int Chan(int x) {
	return (x%2 ? 0 : 1);
}

int countEven(int a[], unsigned int n) {
	int i, r  = 0;
	for (i = 0; i < n; i++)
		if (Chan(*(a+i)))
			r++;
	return r;
}

int TongEven(int a[], unsigned int n) {
	int i, s = 0;
	for (i = 0; i < n; i++)
		if (Chan(*(a+i)))
			s += *(a+i);
	return s;
}

void InChan(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		if (Chan(*(a+i)))
			printf("%i ", *(a+i));
	printf("\n");
}

int main() {
	unsigned int n;
	printf("n = ");
	scanf("%u", &n);
	int a[n];
	Nhap(a, n);
	printf("So phan tu chan: %i\n", countEven(a, n));
	printf("Cac phan tu chan:\n");
	InChan(a, n);
	printf("Tong phan tu chan: %i\n", TongEven(a, n));
	return 0;
}
