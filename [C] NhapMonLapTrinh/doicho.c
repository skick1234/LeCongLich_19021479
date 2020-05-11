#include <stdio.h>

void f(int* a, int* b, int* c){
	int tmp;
	tmp = *b;
	*b = *a;
	*a = *c;
	*c = tmp;
}

int main(){
	int a, b, c;
	printf("a = ");
	scanf("%i", &a);
	printf("b = ");
	scanf("%i", &b);
	printf("c = ");
	scanf("%i", &c);
	printf("\nTruoc khi goi ham f, a = %i, b = %i, c = %i", a, b, c);
	f(&a, &b, &c);
	printf("\nSau khi goi ham f, a = %i, b = %i, c = %i", a, b, c);
	return 0;
}
