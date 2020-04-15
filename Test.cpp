#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    int a[n], ucln;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        ucln = gcd(ucln, a[i]);
    cout << ucln;
    return 0;
}