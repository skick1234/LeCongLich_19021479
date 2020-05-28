#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    bool c = true;
    for(int i = 0 ; i < l/2 ; i++) {
        if(s[i] != s[l-i-1]) {
            c = false;
            break;
        }
    }
    cout << (c ? "Yes" : "No");
    return 0;
}