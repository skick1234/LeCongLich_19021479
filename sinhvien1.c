#include <stdio.h>

struct sv {
    char hoten[50];
    int tuoi;
    char diemthi[50];
};

int main(){
    struct sv sv1, sv2;
    printf("Nhap thong tin sinh vien 1\nHo va ten: ");
    gets(sv1.hoten);
    printf("Tuoi: ");
    scanf("%i", &sv1.tuoi);
    fflush(stdin);
    printf("Diem thi: ");
    gets(sv1.diemthi);
    printf("\nNhap thong tin sinh vien 2\nHo va ten: ");
    gets(sv2.hoten);
    printf("Tuoi: ");
    scanf("%i", &sv2.tuoi);
    fflush(stdin);
    printf("Diem thi: ");
    gets(sv2.diemthi);
    printf("\nThong tin sinh vien 1:\nHo va ten: %s\nTuoi: %i\nDiem thi: %s", sv1.hoten, sv1.tuoi, sv1.diemthi);
    printf("\nThong tin sinh vien 2:\nHo va ten: %s\nTuoi: %i\nDiem thi: %s", sv2.hoten, sv2.tuoi, sv2.diemthi);
    // Nhuoc diem: Phai lap lai nhieu lan cac lenh nhap xuat -> dai dong
    return 0;
}
