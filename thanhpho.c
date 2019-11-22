#include <stdio.h>

struct thanhpho {
    char ten[50];
    int thunhap;
    int danso;
    double docviet;
};

void Nhap(struct thanhpho *tp){
    printf("\nNhap thong tin thanh pho\nTen: ");
    fflush(stdin);
    gets(tp->ten);
    printf("Tong thu nhap: ");
    scanf("%i", &tp->thunhap);
    printf("Dan so: ");
    scanf("%i", &tp->danso);
    printf("Ti le doc viet: ");
    scanf("%lf", &tp->docviet);
}

void Xuat(struct thanhpho tp) {
    printf("\nThanh pho: %s\nTong thu nhap: %i\nDan so: %i\nTi le doc viet: %lg\%", tp.ten, tp.thunhap, tp.danso, tp.docviet);
}

int main(){
    int n, i, max_tn = 0, max_dv = 0;
    printf("So thanh pho: ");
    scanf("%i", &n);
    struct thanhpho tp[n];
    for (i = 0; i < n; i++)
        Nhap(&tp[i]);
    for (i = 0; i < n; i++) {
        if (tp[i].thunhap > tp[max_tn].thunhap)
            max_tn = i;
        if (tp[i].docviet > tp[max_dv].docviet)
            max_dv = i;
    }
    printf("Thanh pho co tong thu nhap cao nhat la: %s (%i)\n", tp[max_tn].ten, tp[max_tn].thunhap);
    printf("Thanh pho co ti le doc viet la: %s (%lg)", tp[max_dv].ten, tp[max_dv].docviet);
    return 0;
}
