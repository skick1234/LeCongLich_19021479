#include <stdio.h>

unsigned int ucln(unsigned int x, unsigned int y);

int main() {
	unsigned int a, b;
	printf("Tinh UCLN(a, b)\nNhap a, b: ");
	scanf("%u %u", &a, &b);
	printf("UCLN(%u, %u) = %u", a, b, ucln(a, b));
	return 0;
}

unsigned int ucln(unsigned int x, unsigned int y) {
	if (x == y) return x;
	else if (x > y) return ucln(x-y, y);
	else return ucln(x, y-x);
}