#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tong = 0;
    for (int i = 2; i < n; i++) {
        bool check = true;
        for (int j = 2; j <= n/2; j++) 
            if (i%j == 0) {
                check = false;
                break;
            }
        if (check)
            tong += i;
    }
    cout << tong;
    return 0;
}