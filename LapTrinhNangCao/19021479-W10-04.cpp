#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, tmp;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        auto low = lower_bound(v.begin(), v.end(), q);
        if (*low == q)
            cout << "Yes " << (low - v.begin() + 1) << endl;
        else
            cout << "No " << (low - v.begin() + 1) << endl;
    }
    return 0;
}