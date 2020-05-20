#include <stdio.h>
#include <string.h>

void delSpace(char xau[], int s) {
    int i, len = strlen(xau);
    for (i = s; i < len; i++)
        xau[i] = xau[i+1];
}

int isLow(char x) {
    return ((x >= 'a' && x <= 'z') ? 1 : 0);
}

int main() {
    char xau[101], tim;
    printf("Nhap chuoi: ");
    gets(xau);
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
        if ((i == 0 && isLow(xau[i])) || (xau[i-1] == ' ' && isLow(xau[i])))
            xau[i] = (char) xau[i] - 32;
        i++;
    }
    puts(xau);
    return 0;
}
