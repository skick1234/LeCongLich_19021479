#include <stdio.h>

typedef struct phanso {
    double tuso;
    double mauso;
} phanso;

void nhap(phanso *ps) {
    printf("Nhap tu so: ");
    scanf("%lf", &ps->tuso);
    printf("Nhap mau so: ");
    scanf("%lf", &ps->mauso);
    while (ps->mauso == 0) {
        printf("Nhap lai mau so (khac 0): ");
        scanf("%lf", &ps->mauso);
    }
}

void xuat(phanso ps) {
    printf("%lg/%lg ", ps.tuso, ps.mauso);
}

int ucln(int x, int y) {
	return (y == 0) ? x : ucln(y, x%y);
}

void nhantumau(phanso *ps, double nt) {
    ps->tuso = ps->tuso*nt;
    ps->mauso = ps->mauso*nt;
}

void rutgon(phanso *ps) {
    int am = 0;
    if (ps->tuso < 0 && ps->mauso < 0) {
        ps->mauso = ps->mauso * -1;
        ps->tuso = ps->tuso * -1;
    } else if (ps->tuso < 0) {
        ps->tuso = ps->tuso * -1;
        am = 1;
    } else if (ps->mauso < 0) {
        ps->mauso = ps->mauso * -1;
        am = 1;
    }
    while((int) ps->tuso != (double) ps->tuso || (int) ps->mauso != (double) ps->mauso)
        nhantumau(ps, 10);
    int uc = ucln(ps->tuso, ps->mauso);
    ps->tuso = ps->tuso/uc * (am ? -1 : 1);
    ps->mauso = ps->mauso/uc;
}

void quydong(phanso *a, phanso *b) {
    rutgon(a);
    rutgon(b);
    int uc = ucln(a->mauso, b->mauso);
    int nt_a = b->mauso/uc;
    int nt_b = a->mauso/uc;
    nhantumau(a, nt_a);
    nhantumau(b, nt_b);
}

phanso tong(phanso a, phanso b) {
    if (a.mauso != b.mauso)
        quydong(&a, &b);
    phanso tong = {a.tuso + b.tuso, a.mauso};
    rutgon(&tong);
    return tong;
}

phanso hieu(phanso a, phanso b) {
    if (a.mauso != b.mauso)
        quydong(&a, &b);
    phanso hieu = {a.tuso - b.tuso, a.mauso};
    rutgon(&hieu);
    return hieu;
}

phanso tich(phanso a, phanso b) {
    phanso tich = {a.tuso*b.tuso, a.mauso*b.mauso};
    rutgon(&tich);
    return tich;
}

phanso thuong(phanso a, phanso b) {
    phanso c = {b.mauso, b.tuso};
    return tich(a, c);
}

int main(){
    phanso a, b;
    printf("Nhap phan so thu nhat\n");
    nhap(&a);
    printf("Phan so thu nhat: ");
    xuat(a);
    printf("\nNhap phan so thu hai\n");
    nhap(&b);
    printf("Phan so thu hai: ");
    xuat(b);

    printf("\nTong = ");
    xuat(tong(a, b));
    printf("\nHieu = ");
    xuat(hieu(a, b));
    printf("\nTich = ");
    xuat(tich(a, b));
    printf("\nThuong = ");
    xuat(thuong(a, b));
    return 0;
}
