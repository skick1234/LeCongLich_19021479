#include <iostream>
using namespace std;

int main () {
    float n, am = 0, duong = 0, khong = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) khong++;
        else if (tmp > 0) duong++;
        else am++;
    }
    cout << "\nAm: " << am/n*100 << "%\n" <<
        "Duong: " << duong/n*100 << "%\n" <<
        "Khong: " << khong/n*100 << "%\n";
    return 0;
}
