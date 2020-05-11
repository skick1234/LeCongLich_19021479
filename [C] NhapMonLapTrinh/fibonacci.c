#include <stdio.h>

unsigned int fibonacci(unsigned int n) {
	if (n <= 1) return n;
	else return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
	for (int i = 0; i < 10; ++i)
	{
		printf("%u\t", fibonacci(i));
	}
}