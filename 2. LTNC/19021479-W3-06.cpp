#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, a;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        if(isalpha(s[i])) {
            a = isupper(s[i]) ? 'A' : 'a';
            s[i] = a + (s[i] - a + k)%26;
        }
    }
    cout << s;
    return 0;
}