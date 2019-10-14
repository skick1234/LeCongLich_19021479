#include <stdio.h>
#include <math.h>

void Nhap(int (*a)[], unsigned int n);
void Xuat(int a[], unsigned int n);
int NguyenTo(int n);
void XuatNT(int a[], unsigned int n);
int TongBPNT(int a[], unsigned int n);
int ChinhPhuong(int n);
void XuatCP(int a[], unsigned int n);
int Fibonaxi(int n);
void XuatFibo(int a[], unsigned int n);
void SapXep(int a[], unsigned int n);
void Chen(int a[], unsigned int n, unsigned int vt, int x);
int Tim(int a[], unsigned int n, int x);
void Xoa(int a[], unsigned int n, int x);
void InMaxMin(int a[], unsigned int n);

int main() {
	unsigned int n;
	do {
		printf("Nhap so phan tu n ( n > 0 ): ");
		scanf("%u", &n);
	} while (n <= 0);
	// 1. Nhập vào một dãy số nguyên có n phần tử
	int a[n];
	Nhap(&a, n);
	// 2. Xuất ra dãy số nguyên vừa nhập
	printf("Day so nguyen vua nhap la:\n");
	Xuat(a, n);
	// 3. Xuất ra các phần tử của mảng là số nguyên tố nhỏ hơn 100
	XuatNT(a, n);
	// 4. In ra tổng bình phương của các phần tử là số nguyên tố
	printf("Tong binh phuong cac phan tu la so nguyen to la: %i\n", TongBPNT(a, n));
	// 5. In ra các phần tử của mảng đã nhập là số chính phương < 50
	XuatCP(a, n);
	// 6. In ra các phần tử của mảng đã nhập là số Fibonaxi
	XuatFibo(a, n);
	// 7. In ra mảng đã nhập theo thứ tự được sắp xếp tăng dần
	// 8. In ra phần tử lớn nhất và phần tử bé nhất của mảng.
	SapXep(a, n);
	// 9. Chèn thêm một phần tử vào mảng và in ra dãy mới
	int c;
	unsigned int vt;
	printf("Nhap phan tu muon chen them: ");
	scanf("%i", &c);
	printf("Nhap vi tri chen them (0 - %u): ", n-1);
	scanf("%i", &vt);
	Chen(a, n, vt, c);
	// 10. Xóa một phần tử có mặt trong mảng và in ra dãy mới.
	int x;
	printf("Nhap phan tu muon xoa: ");
	scanf("%i", &x);
	Xoa(a, n, x);
	return 0;
}

// 1. Nhap(a, n): nhập dãy số từ bàn phím
void Nhap(int (*a)[], unsigned int n) {
	int i, tmp;
	printf("Nhap day so: ");
	for (i = 0; i < n; ++i) {
		scanf("%i", &tmp);
		(*a)[i] = tmp;
	}
}


// 2. Xuat(a, n): in dãy số ra màn hình
void Xuat(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%i ", a[i]);
	printf("\n");
}
