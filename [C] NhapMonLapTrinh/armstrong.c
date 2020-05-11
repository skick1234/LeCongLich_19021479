#include <stdio.h>
#include <math.h>

int isAS(unsigned int x) {
	if (x == pow(x/100, 3) + pow(x/10%10, 3) + pow(x%10, 3))
		return 1;
	else
		return 0;
}

int main() {
	int i, j = 0;
	for (i = 100; i <= 999; ++i) {
		if (isAS(i)) {
			printf("%i\t", i);
			j++;
		}
	}
	printf("\nCo %i so armstrong.", j);
	return 0;
}