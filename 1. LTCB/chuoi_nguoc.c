#include <stdio.h>
#include <string.h>

int main() {
    char xau[101], tim;
    printf("Nhap chuoi: ");
    gets(xau);
    int i, end = strlen(xau) - 1, start, j;
    for (i = end; i >= 0; i--)
        if (i == 0 || xau[i] == ' ') {
            if (i == 0)
                start = 0;
            else
                start = i + 1;
            for (j = start; j <= end; j++)
                printf("%c", xau[j]);
            end = i-1;
            printf(" ");
        }
    return 0;
}
