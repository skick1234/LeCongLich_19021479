#include <stdio.h>

int ucln(int x, int y) {
	return (y == 0) ? x : ucln(y, x%y);
}

int main() {
	int a, b;
	printf("Tinh UCLN(a, b)\nNhap a, b: ");
	scanf("%u %u", &a, &b);
	printf("UCLN(%u, %u) = %u", a, b, ucln(a, b));
	return 0;
}
