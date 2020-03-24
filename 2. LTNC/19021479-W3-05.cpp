#include <bits/stdc++.h>

using namespace std;


int main(){
    int n; 
    cin >> n;
    string h = "hackerrank", s;
    for(int a = 0; a < n; a++) {
        int j=0;
        cin >> s;
        for(int i=0; i < s.size() && j < h.size(); i++)
            if(h[j]==s[i])
                j++;
        if(j == h.size())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}