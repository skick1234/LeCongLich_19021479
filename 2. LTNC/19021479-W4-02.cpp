#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mi, ma, c = 0, l = 0, t;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> t;
        if (mi > t || i == 0) mi = t;
        if (ma < t || i == 0) ma = t;
        if (t%2) l++;
        else c += t;
    }
    cout << "Min: " << mi << endl <<
            "Max: " << ma << endl <<
            "Sum of even: " << c << endl <<
            "Num of odd: " << l << endl;
    return 0;
}