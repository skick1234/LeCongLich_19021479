#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool check = false;
    for (int i = 1; i < n-1; i++) {
        int trai = 0, phai = 0;
        for (int k = 0; k < i; k++)
            trai += a[k];
        for (int k = i+1; k < n; k++)
            phai += a[k];
        if (trai == phai) {
            check = true;
            break;
        }
    }
    cout << (check ? "YES" : "NO");
    return 0;
}
