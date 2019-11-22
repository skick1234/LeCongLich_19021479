#include <stdio.h>

struct sv {
    char hoten[50];
    int tuoi;
    char diemthi[50];
};

void Nhap(struct sv *sv){
    printf("Nhap thong tin sinh vien\nHo va ten: ");
    gets(sv->hoten);
    printf("Tuoi: ");
    scanf("%i", &sv->tuoi);
    fflush(stdin);
    printf("Diem thi: ");
    gets(sv->diemthi);
}

void Xuat(struct sv *sv) {
    printf("\nThong tin sinh vien\nHo va ten: %s\nTuoi: %i\nDiem thi: %s", sv->hoten, sv->tuoi, sv->diemthi);
}

int main(){
    struct sv sv1, sv2;
    Nhap(&sv1);
    Nhap(&sv2);
    Xuat(&sv1);
    Xuat(&sv2);
    // Nhuoc diem: Phai khai bao va viet ham nhap xuat voi moi sinh vien;
    return 0;
}
