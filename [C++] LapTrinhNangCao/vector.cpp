#include <bits/stdc++.h>

using namespace std;

struct Vector {
    double x;
    double y;

    Vector(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Vector cong(Vector v) {
        return Vector(x + v.x, y + v.y);
    }
    Vector tru(Vector v) {
        return Vector(x - v.x, y - v.y);
    }
    double khoangCach(Vector v) {
        return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }
    void print() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    double x1, y2, x2, y1;
    cout << "Nhap x1: ";
    cin >> x1;
    cout << "Nhap y1: ";
    cin >> y1;
    cout << "Nhap x2: ";
    cin >> x2;
    cout << "Nhap y2: ";
    cin >> y2;
    Vector v1 = Vector(x1, y1), v2 = Vector(x2, y2);
    cout << "Tong: "; v1.cong(v2).print();
    cout << endl << "Hieu: "; v1.tru(v2).print();
    cout << endl << "Khoang Cach: " << v1.khoangCach(v2);
    return 0;
}