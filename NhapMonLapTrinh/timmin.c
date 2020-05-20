#include <stdio.h>

void Nhap(double a[], unsigned int n){
 	int i;
 	printf("Nhap day a[]: ");
 	for (i = 0; i < n; i++)
 		scanf("%lf", (a+i));
 }

double *minimum(double* a, int n)
{
    int i;
    double  *min = &a[0];
    for (i = 1; i < n; i++)
        if (a[i] < *min)
            min = &a[i];
    return min;
}

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%i", &n);
	double a[n];
	Nhap(a, n);
	double *min = minimum(a, n);
	if (min != NULL)
		printf("Phan tu nho nhat la: %lg", *min);
	else
		printf("Khong tim duoc phan tu nho nhat.");
	return 0;
}

