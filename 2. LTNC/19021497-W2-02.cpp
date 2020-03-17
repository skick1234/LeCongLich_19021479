#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    if (x1 < x2) {
        if (v1 > v2) {
            while (x1 < x2) {
                x1 += v1;
                x2 += v2;
            }
        }
    } else {
        if (v2 > v1) {
            while (x2 < x1) {
                x1 += v1;
                x2 += v2;
            }
        }
    }
    if (x1 == x2) cout << "YES";
    else cout << "NO";
    return 0;
}
