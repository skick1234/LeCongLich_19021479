#include <stdio.h>
//Tinh tong va hieu cua hai so
void tinhTongHieu(int a, int b, int *tong, int *hieu){
	*tong = a + b;
	*hieu = a - b;
}
//Chuong trinh chinh
int main(){
	int a, b, tong, hieu;
	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	tinhTongHieu(a, b, &tong, &hieu);
	printf("tong(%d, %d) = %d\n", a, b, tong);
	printf("hieu(%d, %d) = %d\n", a, b, hieu);
}
