#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "So phan tu: ";
    cin >> n;
    cout << "Nhap day so:\n";
    long int a[n], m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, abs(a[i]));
    }
    long int b[m+1] = {};
    for (int i = 0; i < n; i++) {
        if (b[abs(a[i])] + a[i] == 0) {
            cout << "Cap so co tong = 0: \t" << -abs(a[i]) << " & " << abs(a[i])  << endl;
            break;
        } else b[abs(a[i])] = a[i];
    }
    return 0;
}
