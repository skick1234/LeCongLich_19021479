#include <stdio.h>

int isLeapYear(unsigned int y);

int main() {
	unsigned int a, b, i;
	printf("Nhap a, b: ");
	scanf("%u %u", &a, &b);
	for (i = a; i <= b; ++i)
		if (isLeapYear(i) == 1) printf("%d, ", i);
	return 0;
}

int isLeapYear(unsigned int y) {
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		return 1;
	else
		return 0;
}
