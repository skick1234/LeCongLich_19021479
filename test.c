#include <stdio.h>
#include <stdlib.h>

#define N 100

void nhapfile(char tenfile[], int* mang, int* soluong);
void xuatfile(char tenfile[], int* mang, int soluong);
void hienthimang(int* mang, int n);
void sapxep(int* mang, int soluong);
int tongpt(int* mang, int soluong);

int main() {
	int mang[N], soluong;
	char tenfile[50];
	printf("Nhap ten file chua day so: ");
	gets(tenfile);
	fflush(stdin);
	nhapfile(tenfile, mang, &soluong);
	printf("\nDay so da nhap la:\n");
	hienthimang(mang, soluong);

	sapxep(mang, soluong);
	printf("Day so sau khi sap xep la:\n");
	hienthimang(mang, soluong);

	printf("Tong cac phan tu cua mang la: %d\n\n", tongpt(mang, soluong));

	printf("Nhap ten file luu mang: ");
	gets(tenfile);
	fflush(stdin);
	xuatfile(tenfile, mang, soluong);
	return 0;
}

void nhapfile(char tenfile[], int* mang, int* soluong) {
	FILE* f;
	f = fopen(tenfile, "r");
	int i = 0;
	if (f == NULL) {
		fclose(f);
		printf("File khong ton tai, tao file du lieu moi.\nNhap so phan tu cua day so: ");
		scanf("%d", soluong);
		f = fopen(tenfile, "w");
		for(i = 0; i < *soluong; i++) {
			do {
				printf("Nhap phan tu %d ( > 0): ", i+1);
				scanf("%d", &mang[i]);
				fflush(stdin);
			} while (mang[i] <= 0);
			putw(mang[i], f);
		}
	} else {
		int n;
		while ((n = getw(f)) != EOF)
			mang[i++] = n;
		*soluong = i;
	}
	fclose(f);
}

void xuatfile(char tenfile[], int* mang, int soluong) {
	FILE* f = fopen(tenfile, "w");
	int i;
	for (i = 0; i < soluong; i++)
		putw(mang[i], f);
	fclose(f);
}

void hienthimang(int* mang, int n) {
	int i;
	for(i=0; i<n; i++)
		printf("%d ", mang[i]);
	printf("\n");
}

void sapxep(int* mang, int soluong) {
	int i, j;
	for (i = 0; i < soluong; i++) {
		int min_id = i;
		for (j = i; j < soluong; j++)
			if (mang[j] < mang[min_id])
				min_id = j;
		int min = mang[min_id];
		mang[min_id] = mang[i];
		mang[i] = min;
	}
}

int tongpt(int* mang, int soluong) {
	int tongpt = 0, i;
	for (i = 0; i < soluong; i++)
		tongpt += mang[i];
	return tongpt;
}
