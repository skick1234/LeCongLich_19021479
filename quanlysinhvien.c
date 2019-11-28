#include <stdio.h>
#include <string.h>

typedef struct ngay {
    int ngay;
    int thang;
    int nam;
} ngay;

typedef struct sinhvien {
    char hoten[30];
    ngay sinh;
    float tin;
    float toan;
    float tienganh;
} sinhvien;

void Nhap(sinhvien a[], int n) {
    int i;
    printf("Nhap danh sach gom %i sinh vien\n", n);
    for (i = 0; i < n; i++) {
        printf("%i. Ho ten: ", i+1);
        fflush(stdin);
        gets(a[i].hoten);
        printf("Ngay sinh: ");
        scanf("%i", &a[i].sinh.ngay);
        printf("Thang sinh: ");
        scanf("%i", &a[i].sinh.thang);
        printf("Nam sinh: ");
        scanf("%i", &a[i].sinh.nam);
        printf("Diem tin: ");
        scanf("%f", &a[i].tin);
        printf("Diem toan: ");
        scanf("%f", &a[i].toan);
        printf("Diem tieng anh: ");
        scanf("%f", &a[i].tienganh);
    }
}

float DiemTB(sinhvien sv) {
    return (sv.tin+sv.toan+sv.tienganh)/3;
}

char *XepLoai(sinhvien sv) {
    float tb = DiemTB(sv);
    if (tb >= 9)
        return "Xuat sac";
    else if (tb >= 8)
        return "Gioi";
    else if (tb >= 6.5)
        return "Kha";
    else if (tb >= 5)
        return "Trung binh";
    else
        return "Yeu";
}

sinhvien Tim(char *ht, sinhvien a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(ht, a[i].hoten) == 0)
            return a[i];
    sinhvien sv = {""};
    return sv;
}

int TimThay(sinhvien x) {
    return strcmp(x.hoten, "");
}

void Xuat(sinhvien a[], int n) {
    int i;
    printf("\nDanh sach %i sinh vien\n", n);
    printf("Ho ten\t\t\t\tNgay sinh\tTin\tToan\tAnh\tDiem TB\t\tXep loai\n");
    for (i = 0; i < n; i++)
        printf("%-30s\t%2i/%2i/%4i\t%.2f\t%.2f\t%.2f\t%.2f\t\t%s\n", a[i].hoten, a[i].sinh.ngay, a[i].sinh.thang, a[i].sinh.nam, a[i].tin, a[i].toan, a[i].tienganh, DiemTB(a[i]), XepLoai(a[i]));
}

void XuatTT(sinhvien sv) {
    printf("Ho ten: %s\nNgay sinh: %i/%i/%i\nDiem tin: %.2f\nDiem toan: %.2f\nDiem tieng anh: %.2f\nDiem TB: %.2f\nXep loai: %s", sv.hoten, sv.sinh.ngay, sv.sinh.thang, sv.sinh.nam, sv.tin, sv.toan, sv.tienganh, DiemTB(sv), XepLoai(sv));
}

void HoanVi(sinhvien *sv1, sinhvien *sv2) {
    sinhvien sv;
    sv = *sv1;
    *sv1 = *sv2;
    *sv2 = sv;
}

void SapXep(sinhvien *sv, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int maxt = i;
        for (j = i; j < n; j++)
            if (sv[j].tin > sv[maxt].tin)
                maxt = j;
        HoanVi(&sv[i], &sv[maxt]);
    }
}

void Xoak(sinhvien a[], int *n, int k) {
    int i;
	if (k <= *n) {
		for (i = k; i < *n; i++)
			a[i] = a[i+1];
		(*n)--;
	}
}

int TimSTT(char *ht, sinhvien a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(ht, a[i].hoten) == 0)
            return i;
    return -1;
}

void XoaSinhVien(sinhvien a[], int *n) {
    int i;
    char c[30];
    printf("\n\nNhap ten sinh vien can xoa: ");
    fflush(stdin);
    gets(c);
	int x = TimSTT(c, a, *n);
	if (x != -1)
        Xoak(a, n, x);
}

int main() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%i", &n);
    sinhvien a[n];
    Nhap(a, n);
    SapXep(a, n);
    Xuat(a, n);
    char x[30];
    printf("\nNhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(x);
    sinhvien t = Tim(x, a, n);
    if (TimThay(t))
        XuatTT(t);
    else
        printf("Khong tim thay sinh vien.");
    XoaSinhVien(a, &n);
    Xuat(a, n);
    return 0;
}
