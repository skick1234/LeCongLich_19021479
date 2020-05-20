#include <stdio.h>

int sont(unsigned int n);

int main() {
	unsigned int n, i = 2, dem = 0;
	printf("Nhap n: ");
	scanf("%u", &n);
	while (dem < n) {
		if (sont(i)) {
			printf("%u\t", i);
			dem++;
		}
		i++;
	}
}

int sont(unsigned int n) {
	if (n <= 1) return 0;
	else {
		int i;
		for (i = 2; i <= n/2 ; ++i)	
			if (n % i == 0) return 0;
		return 1;
	}

}