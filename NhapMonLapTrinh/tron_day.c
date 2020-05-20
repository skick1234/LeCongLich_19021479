#include <stdio.h>

int main(){
	// Input
	unsigned int n;
	printf("Nhap so phan tu n = ");
	scanf("%u", &n);
	int i, j, k, a[n], b[n], c[2*n];
	printf("Nhap day thu nhat: ");
	for(i = 0; i < n; i++)
		scanf("%i", (a+i));
	printf("Nhap day thu hai: ");
	for(i = 0; i < n; i++)
		scanf("%i", (b+i));

	// 1. Vua tron vua sap xep
	printf("\nYC1: Vua tron vua sap xep:\n");
	i = 0; j = 0; k = 0;
	while (i < n || j < n) {
		if (j == n || (i != n && a[i] < b[j]))
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	for (i = 0; i < 2*n; i++)
		printf("%i ", *(c+i));

	// 2. Tron xong sap xep
	printf("\nYC2: Tron xong sap xep:\n");
	for (i = 0; i < n; i++) {
		c[i] = a[i];
		c[i+n] = b[i];
	}
	int min_id, tmp;
	for (i = 0; i < 2*n; i++) {
		min_id  = i;
		for (j = i; j < 2*n; j++)
			if (c[min_id] > c[j])
				min_id = j;
		tmp = c[i];
		c[i] = c[min_id];
		c[min_id] = tmp;
	}
	for (i = 0; i < 2*n; i++)
		printf("%i ", *(c+i));
	return 0;
}
