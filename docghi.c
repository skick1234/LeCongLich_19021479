 #include <stdio.h>
 
 int main() {
 	unsigned int n;
 	printf("Nhap n: ");
 	scanf("%u", &n);
 	int a[n], i;
 	printf("Nhap day a[]: ");
 	for (i = 0; i < n; i++)
 		scanf("%i", (a+i));
 	printf("In xuoi:\n");
 	for (i = 0; i < n; i++)
 		printf("%i ", *(a+i));
 	printf("\nIn nguoc:\n", *(a+i));
 	for (i = n; i > 0; i--)
 		printf("%i ", *(a+i-1));
 	return 0; 		
 }
