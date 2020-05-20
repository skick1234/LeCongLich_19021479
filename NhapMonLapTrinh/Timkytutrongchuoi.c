#include <stdio.h>
#include <string.h>

int main() {
    char xau[101], tim;
    printf("Nhap chuoi (toi da 100 ki tu): ");
    gets(xau);
    printf("Nhap ki tu can tim: ");
    scanf("%c", &tim);
    int i, l = strlen(xau), thay = 0;
    for (i = 0; i < l; i++)
        if (xau[i] == tim)
            thay++;
    if (thay)
        printf("Ki tu %c xuat hien %i lan trong chuoi.", tim, thay);
    else
        printf("Ki tu %c khong xuat hien trong chuoi", tim);
    return 0;
}
