#include <iostream>
using namespace std;

int main() {
    int a;
    do {
        cout << "Nhap a thoa man 4<=a<=6: ";
        cin >> a;
    } while (4>a || a>6);
    cout << "a = " << a;
    return 0;
}