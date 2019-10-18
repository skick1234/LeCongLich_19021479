#include <stdio.h>
#include <math.h>

void Nhap(int a[], unsigned int n);
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

int main() {
	unsigned int n;
	do {
		printf("Nhap so phan tu n ( n > 0 ): ");
		scanf("%u", &n);
	} while (n <= 0);
	int a[n], b[n], i, c, x, vt;

	// 1. Nhập vào một dãy số nguyên có n phần tử 1
	Nhap(a, n);

	// 2. Xuất ra dãy số nguyên vừa nhập 9
	printf("\nDay so nguyen vua nhap la:\n");
	Xuat(a, n);

	// 3. Xuất ra các phần tử của mảng là số nguyên tố nhỏ hơn 100 0
	XuatNT(a, n);

	// 4. In ra tổng bình phương của các phần tử là số nguyên tố 2
	printf("\nTong binh phuong cac phan tu la so nguyen to la:\n%i\n", TongBPNT(a, n));

	// 5. In ra các phần tử của mảng đã nhập là số chính phương < 50 1
	XuatCP(a, n);

	// 6. In ra các phần tử của mảng đã nhập là số Fibonaxi 4
	XuatFibo(a, n);

	// 7. In ra mảng đã nhập theo thứ tự được sắp xếp tăng dần 7
	for (i = 0; i < n; i++)
		b[i] = a[i];
	SapXep(b, n);
	printf("\nDay so sau khi sap xep la:\n");
	Xuat(b, n);

	// 8. In ra phần tử lớn nhất và phần tử bé nhất của mảng. 9
	printf("\nPhan tu lon nhat = %i\nPhan tu be nhat = %i\n", b[0], b[n-1]);

	// 9. Chèn thêm một phần tử vào mảng và in ra dãy mới
	for (i = 0; i < n; i++)
		b[i] = a[i];
	printf("\nNhap phan tu muon chen them: ");
	scanf("%i", &c);
	printf("Nhap vi tri chen them (0 - %u): ", n);
	scanf("%i", &vt);
	Chen(b, n, vt, c);
	printf("Day so sau khi chen la:\n");
	Xuat(b, (vt >= 0 && vt <= n ? n+1 : n));

	// 10. Xóa một phần tử có mặt trong mảng và in ra dãy mới.
	for (i = 0; i < n; i++)
		b[i] = a[i];
	printf("\nNhap phan tu muon xoa: ");
	scanf("%i", &x);
	Xoa(b, n, x);
	printf("Day so sau khi xoa la:\n");
	Xuat(b, n);
	return 0;
}

// 1. Nhap(a, n): nhập dãy số từ bàn phím
void Nhap(int a[], unsigned int n) {
	int i, tmp;
	printf("Nhap day so: ");
	for (i = 0; i < n; ++i) {
		scanf("%i", &tmp);
		a[i] = tmp;
	}
}


// 2. Xuat(a, n): in dãy số ra màn hình
void Xuat(int a[], unsigned int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%i ", a[i]);
	printf("\n");
}

// 3. NguyenTo(n): kiểm tra một số có phải là số nguyên tố không
int NguyenTo(int n) {
	int i;
	if (n <= 1)
		return 0;
	for (i = 2; i <= n/2; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

// 4. XuatNT(a,n): in ra màn hình các phần tử là số nguyên tố nhỏ hơn 100
void XuatNT(int a[], unsigned int n) {
	int i;
	printf("\nDay so nguyen to la:\n");
	for (i = 0; i < n; i++)
		if (NguyenTo(a[i]) && a[i] < 100)
			printf("%i ", a[i]);
	printf("\n");
}

// 5. TongBPNT(a,n): tính tổng bình phương các phần tử là số nguyên tố
int TongBPNT(int a[], unsigned int n) {
	int i, s = 0;
	for (i = 0; i < n; i++)
		if (NguyenTo(a[i]))
			s += a[i]*a[i];
	return s;
}

// 6. ChinhPhuong(n): Hàm kiểm tra một số có phải là số chính phương không
int ChinhPhuong(int n) {
	return ((int) sqrt(n) == (double) sqrt(n) && n >= 0 ? 1 : 0);
}

// 7. XuatCP(a,n): in ra các phần tử của mảng là số chính phương <50
void XuatCP(int a[], unsigned int n) {
	int i;
	printf("\nDay so chinh phuong la:\n");
	for (i = 0; i < n; i++)
		if (ChinhPhuong(a[i]) && a[i] < 50)
			printf("%i ", a[i]);
	printf("\n");
}

// 8. Fibonaxi(n): Hàm kiểm tra một số có phải là số fibonaxi không?
int Fibonaxi(int n) {
	int f1 = 0, f2 = 1, tmp;
	do {
		if (f1 == n || f2 == n)
			return 1;
		tmp = f2;
		f2 = f1+f2;
		f1 = tmp;
	} while (f1 < n || f2 < n);
	return 0;
}

// 9. XuatFibo(a,n): in ra các phần tử của mảng là số Fibonaxi
void XuatFibo(int a[], unsigned int n) {
	int i;
	printf("\nDay so fibo la:\n");
	for (i = 0; i < n; i++)
		if (Fibonaxi(a[i]) && a[i] < 50)
			printf("%i ", a[i]);
	printf("\n");
}

// 10. SapXep(a,n): Sắp xếp mảng tăng dần
void SapXep(int a[], unsigned int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min_id = i;
		for (j = i; j < n; j++)
			if (a[j] < a[min_id])
				min_id = j;
		int min = a[min_id];
		a[min_id] = a[i];
		a[i] = min;
	}
}

// In ra phần tử lớn nhất và phần tử bé nhất của mảng. 19021479
// 11. Chen(a, n,vt,x): Chèn thêm một phần tử x vào vị trí vt của mảng
void Chen(int a[], unsigned int n, unsigned int vt, int x) {
	int i;
	for (i = ++n; i > vt; i--)
		a[i] = a[i-1];
	a[vt] = x;
}

// 12. Tim(a,n,x): Tìm một giá trị x trong mảng, nếu thấy thì trả về vị trí xuất hiện đầu tiên, 19021479
// không thấy thì trả về câu không tìm thấy
int Tim(int a[], unsigned int n, int x) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}

// 13. Xoa(a,n,x): xóa một phần tử x có xuất hiện đầu tiên trong mảng
void Xoa(int a[], unsigned int n, int x) {
	x = Tim(a, n, x);
	if (x != -1) {
		int i;
		for (i = x; i < n; i++)
			a[i] = a[i+1]
	}
}