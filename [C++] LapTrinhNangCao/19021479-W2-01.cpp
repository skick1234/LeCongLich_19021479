#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int x = 0, num = n;
        while (n >= 1) {
            int d = n % 10;
            n /= 10;
            if (d && num % d == 0) x++;
        }
        cout << x << endl;
    }
    return 0;
}
