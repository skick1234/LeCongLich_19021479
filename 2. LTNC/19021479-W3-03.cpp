#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string space, stair;
        for (int j = 0; j < n-i-1; j++)
            space += " ";
        for (int j = 0; j < i+1; j++)
            stair += "#";
        cout << space << stair << endl;
    }

    return 0;
}