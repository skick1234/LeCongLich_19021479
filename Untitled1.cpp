#include <bits/stdc++.h>
using namespace std;

class Complex {
    double a, b;
public:
    Complex(double a = 0, double b = 0) {
        this->a = a; this->b = b;
    };
    friend ostream& operator<<(ostream& os, const Complex& f);
    Complex operator+(const Complex& f) const {
        return Complex(a+f.a, b+f.b);
    };
    Complex operator-(const Complex& f) const {
        return Complex(a-f.a, b-f.b);
    };
};

ostream& operator<<(ostream& os, const Complex& f) {
    if (!f.b) os << f.a;
    else if (!f.a) os << f.b << "i";
    else {
        os << f.a;
        if (f.b > 0) os << "+";
        os << f.b << "i";
    }
    os << endl;
    return os;
}
int main() {
    Complex c = Complex(0,-2);
    Complex c1 = Complex(1,-2);
    Complex c2 = Complex(-2, 3);
    cout << c << c1 << c2 << c1+c2 <<c1-c2;
}
