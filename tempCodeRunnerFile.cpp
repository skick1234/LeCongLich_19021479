#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap N = ";
    cin >> n;
    cout << "Do While" << endl;
    int tong = 0, i = 1;
    do {
        tong += i++;
    } while (i <= n);
    cout << "Tong day so = " << tong << endl;

    cout << "While" << endl;
    tong = 0; i = 1;
    while (i <= n) {
        tong += i++;
    }
    cout << "Tong day so = " << tong << endl;

    cout << "For" << endl;
    tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i;
    }
    cout << "Tong day so = " << tong << endl;

    return 0;
}