#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Nhap N ( N>0 ) = ";
        cin >> n;
    } while (n <= 0);
    cout << "Tong cac so nguyen le nho hon N = ";
    int sum = 0;
    for (int i = 1; i < n; i+=2)
        sum+=i;
    cout << sum;
    return 0;
}