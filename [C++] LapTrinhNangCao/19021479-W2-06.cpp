#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a[100] = {}, tmp, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp]++;
    }
    for (int i = 1; i < 99; i++)
        m = max(m, a[i] + a[i+1]);
    cout << m;
    return 0;
}