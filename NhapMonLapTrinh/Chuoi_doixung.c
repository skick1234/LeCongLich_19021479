#include <stdio.h>
#include <string.h>

int main() {
    char xau[101];
    printf("Nhap chuoi (toi da 100 ki tu): ");
    gets(xau);
    int i, l = strlen(xau), dx = 1, sp = 0;
    for (i = 0; i < l/2; i++) {
        if (xau[i] != xau[l-i-1]) {
            dx = 0;
            break;
        }
        if (xau[i] == ' ')
            sp = 1;
    }
    if (dx) {
        printf("Chuoi doi xung, so ky tu giong nhau: %i", l/2);
        if (sp)
            printf(", tinh ca dau cach");
    } else
        printf("Chuoi khong doi xung");
    return 0;
}
