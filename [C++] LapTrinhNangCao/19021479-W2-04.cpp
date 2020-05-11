#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(vector<int> arr) {
    int a[6] = {};
    for (int x: arr) a[x]++;
    a[0] = 1;
    for (int i = 2; i <= 5; i++)
        if (a[i] > a[a[0]]) a[0] = i;
    return a[0];
}

int main()
{
    int n, a[6] = {}, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp]++;
    }
    a[0] = 1;
    for (int i = 2; i <= 5; i++)
        if (a[i] > a[a[0]]) a[0] = i;
    cout << a[0];
    return 0;
}
