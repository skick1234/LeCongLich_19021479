 #include <stdio.h>
 void Nhap(int a[], unsigned int n){
 	int i;
 	printf("Nhap day a[]: ");
 	for (i = 0; i < n; i++)
 		scanf("%i", (a+i));
 }
 
 void XuatXuoi(int a[], unsigned int n){
 	int i;
 	printf("In xuoi:\n");
 	for (i = 0; i < n; i++)
 		printf("%i ", *(a+i));
 	printf("\n");
 }
 
 void XuatNguoc(int a[], unsigned int n){
 	int i;
 	printf("In nguoc:\n", *(a+i));
 	for (i = n; i > 0; i--)
 		printf("%i ", *(a+i-1));
 	printf("\n");
 }
 
 int main() {
 	unsigned int n;
 	printf("Nhap n: ");
 	scanf("%u", &n);
 	int a[n];
 	Nhap(a, n);
 	XuatXuoi(a, n);
 	XuatNguoc(a, n);
 	return 0; 		
 }
