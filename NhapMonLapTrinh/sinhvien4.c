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
    struct sv sv[10];
    int i;
    for (i = 0; i < 10; i++)
        Nhap(&sv[i]);
    for (i = 0; i < 10; i++)
        Xuat(&sv[i]);
    return 0;
}
