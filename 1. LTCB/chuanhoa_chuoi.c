#include <stdio.h>
#include <string.h>

void delSpace(char xau[], int s) {
    int i, len = strlen(xau);
    for (i = s; i < len; i++)
        xau[i] = xau[i+1];
}

int main() {
    char xau[101], tim;
    printf("Nhap chuoi: ");
    gets(xau);
    puts(xau);
    int i = 0, words = 1;
    while (i < strlen(xau)){
        if ((i == 0 && xau[i] == ' ') || (xau[i] == ' ' && xau[i+1] == ' ')) {
            delSpace(xau, i);
            continue;
        }
        if (i == strlen(xau) - 1 && xau[i] == ' ') {
            delSpace(xau, i--);
            continue;
        }
        if (xau[i] == ' ')
            words++;
        i++;
    }
    puts(xau);
    printf("So ki tu: %d\nSo tu: %d", strlen(xau), words);
    return 0;
}
