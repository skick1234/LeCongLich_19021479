#include <stdio.h>
#include <math.h>

int chinhphuong(int x);

int main() {
	unsigned int a, b, i;
	printf("Nhap a, b: ");
	scanf("%u %u", &a, &b);
	for (i = a; i <= b; ++i)
		if (chinhphuong(i))	printf("%u\t ", i);
	return 0;
}

int chinhphuong(int x) {
	if ((int) sqrt(x) == (double) sqrt(x))
		return 1;
	else
		return 0;
}