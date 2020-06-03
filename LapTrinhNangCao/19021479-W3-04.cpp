#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin >> s;
    int c = 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            c++;
    cout << c;

    return 0;
}