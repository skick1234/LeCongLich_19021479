#include <stdio.h>
#include <string.h>

int main() {
    char *xau = malloc(100);
    printf("Nhap chuoi: ");
    gets(xau);
    strrev(xau);
    puts(xau);
    return 0;
}
