#include <stdio.h>

int isLeapYear(unsigned int y) {
	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		return 1;
	else
		return 0;
}

int main () {
	unsigned int d, m, y;
	printf("Thang: ");
	scanf("%u", &m);
	printf("Nam: ");
	scanf("%u", &y);
	switch (m) {
		case 2:
			d = (isLeapYear(y)) ? 29 : 28;
			break;
		case 4: case 6: case 9: case 11:
			d = 30;
			break;
		default:
			d = 31;
			break;  
	}
	printf("Thang %u nam %u co %u ngay.", m,y,d);
	return 0;
}
