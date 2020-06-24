#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    FILE *fptr;
    fptr = fopen("G:\\TDIEN", "a");
    printf("Nhap so ban ghi: ");
    scanf("%d", &n);
    char tch[50];
    char lh[15];
    int csd, csc, tt;
    for (i = 0; i < n; i++) {
        printf("%d. Ten chu ho: ", i + 1);
        fflush(stdin);
        fgets(tch, 50, stdin);
        fflush(stdin);
        printf("Loai ho: ");
        fgets(lh, 15, stdin);
        printf("Chi so dau: ");
        scanf("%d", &csd);
        printf("Chi so cuoi: ");
        scanf("%d", &csc);
        tt = 0;
        strtok(tch, "\n");
        strtok(lh, "\n");
        if (strcmp(lh, "Gia dinh") == 0)
            tt = 50000 + 450 * (csc - csd);
        else if (strcmp(lh, "Kinh doanh") == 0)
            tt = 60000 + 600 * (csc - csd);
        else if (strcmp(lh, "San xuat") == 0)
            tt = 70000 + 500 * (csc - csd);
        fprintf(fptr, "%s | %s | %d | %d | %d\n", tch, lh, csd, csc, tt);
    }
    fclose(fptr);
    return 0;
}