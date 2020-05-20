#include <stdio.h>

typedef struct ngay {
    int ngay;
    int thang;
    int nam;
} ngay;

typedef struct congnhan {
    char ten[50];
    ngay sinh;
    ngay vaocq;
} congnhan;

void Nhap(congnhan *cn){
    printf("\nNhap thong tin cong nhan\nTen: ");
    fflush(stdin);
    gets(cn->ten);
    printf("Ngay sinh: ");
    scanf("%i", &cn->sinh.ngay);
    printf("Thang sinh: ");
    scanf("%i", &cn->sinh.thang);
    printf("Nam sinh: ");
    scanf("%i", &cn->sinh.nam);
    printf("Ngay vao co quan: ");
    scanf("%i", &cn->vaocq.ngay);
    printf("Thang vao co quan: ");
    scanf("%i", &cn->vaocq.thang);
    printf("Nam vao co quan: ");
    scanf("%i", &cn->vaocq.nam);

}

void Xuat(congnhan cn) {
    printf("\nCong nhan: %s\nNgay sinh: %i/%i/%i\nNgay vao co quan: %i/%i/%i\n", cn.ten, cn.sinh.ngay, cn.sinh.thang, cn.sinh.nam, cn.vaocq.ngay, cn.vaocq.thang, cn.vaocq.nam);
}

int main(){
    int n, i;
    printf("So cong nhan: ");
    scanf("%i", &n);
    congnhan cn[n];
    for (i = 0; i < n; i++)
        Nhap(&cn[i]);
    printf("-----------------------------\nDanh sach cong nhan");
    for (i = 0; i < n; i++)
        Xuat(cn[i]);
    return 0;
}
