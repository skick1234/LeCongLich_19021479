#include <stdio.h>

double Power(double x, unsigned int n);

int main() {
	unsigned int b, d;
	double a, c;
	printf("Tinh A = 2 * a^b + 5*c^d - 10\n");
	printf("Nhap a, b, c, d: ");
	scanf("%lg %u %lg %u", &a, &b, &c, &d);
	printf("A = %lg", (2*Power(a, b) + 5*Power(c, d) - 10));
}

double Power(double x, unsigned int n) {
	int i, p = 1;
	for (i = 1; i <= n; ++i) {
		p *= x;
	}
	return p;
}