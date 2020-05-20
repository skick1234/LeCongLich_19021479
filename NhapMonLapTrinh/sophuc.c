#include <stdio.h>
#include <math.h>

typedef struct complex {
    double real;
    double imag;
} complex;

void Inp(complex *a) {
    printf("Nhap phan thuc: ");
    scanf("%lf", &a->real);
    printf("Nhap phan ao: ");
    scanf("%lf", &a->imag);
}

void Out(complex a) {
    if (a.real)
        printf("%lg ", a.real);
    if (a.imag) {
        if (a.imag > 0 && a.real) {
            if (a.imag == 1)
                printf("+ i");
            else
                printf("+ %lgi", a.imag);
        } else {
            if (a.imag == 1)
                printf("i");
            else if (a.imag == -1)
                printf("- i");
            else
                printf("- %lgi", -a.imag);
        }
    }
    if (!(a.real || a.imag))
        printf("0");
}

double Modul(complex a) {
    return sqrt(pow(a.real, 2) + pow(a.imag, 2));
}

double Arg(complex a) {
    if (Modul(a))
        return asin(a.imag / Modul(a));
    else
        return INFINITY;
}

complex Conjg(complex a) {
    complex c = {a.real, -a.imag};
    return c;
}

complex Sum(complex a, complex b) {
    complex s = {a.real + b.real, a.imag + b.imag};
    return s;
}

complex Sub(complex a, complex b) {
    complex s = {a.real - b.real, a.imag - b.imag};
    return s;
}

complex Mul(complex a, complex b) {
    complex m = {a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real};
    return m;
}

complex DivR(complex a, double b) {
    complex d;
    if (b) {
        d.real = a.real / b;
        d.imag = a.imag / b;
    } else {
        d.real = INFINITY;
        d.imag = 0;
    }
    return d;
}

complex DivC(complex a, complex b) {
    complex d = DivR(Mul(a, Conjg(b)), pow(Modul(b), 2));
    return d;
}

int main() {
    complex a, b;
    printf("Nhap so phuc 1\n");
    Inp(&a);
    printf("Nhap so phuc 2\n");
    Inp(&b);
    printf("\nSo phuc 1 = ");
    Out(a);
    printf("\nSo phuc 2 = ");
    Out(b);
    printf("\nTong = ");
    Out(Sum(a, b));
    printf("\nHieu = ");
    Out(Sub(a, b));
    printf("\nTich = ");
    Out(Mul(a, b));
    printf("\nThuong = ");
    Out(DivC(a, b));
    printf("\nArgument so 1 = %lg\nModul so 1 = %lg", Arg(a), Modul(a));
    printf("\nArgument so 2 = %lg\nModul so 2 = %lg", Arg(b), Modul(b));
    return 0;
}
